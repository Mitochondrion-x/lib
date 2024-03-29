using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using xna = Microsoft.Xna.Framework;
using URWPGSim2D.Common;
using URWPGSim2D.StrategyLoader;
using URWPGSim2D.StrategyHelper;
using System.IO;

namespace URWPGSim2D.Strategy
{
    public class Strategy : MarshalByRefObject, IStrategy
    {
        #region reserved code never be changed or removed
        /// <summary>
        /// override the InitializeLifetimeService to return null instead of a valid ILease implementation
        /// to ensure this type of remote object never dies
        /// </summary>
        /// <returns>null</returns>
        public override object InitializeLifetimeService()
        {
            //return base.InitializeLifetimeService();
            return null; // makes the object live indefinitely
        }
        #endregion

        /// <summary>
        /// 决策类当前对象对应的仿真使命参与队伍的决策数组引用 第一次调用GetDecision时分配空间
        /// </summary>
        private Decision[] decisions = null;
        /// <summary>
        /// 获取队伍名称 在此处设置参赛队伍的名称
        /// </summary>
        /// <returns>队伍名称字符串</returns>
        public string GetTeamName()
        {
            return "白鲸华尔兹";
        }
        public static bool RangeX(float x, float rangeA, float rangeB)
        {
            if (x > rangeA && x < rangeB)
                return true;
            else
                return false;
        }
        public static bool AtRange1(Mission mission,int teamId)
        {
            for (int i = 2; i < 6; i++) 
            {
                if (!RangeX(mission.TeamsRef[teamId].Fishes[i].PositionMm.X, -1600, -1300)) 
                {
                    return false;
                }
            }
            for (int i = 6; i < 10; i++)
            {
                if (!RangeX(mission.TeamsRef[teamId].Fishes[i].PositionMm.X, 1400, 1600)) 
                {
                    return false;
                }
            }
            return true;
        }
        public static int IsDirectionRight(float a, float b)
        {
            float deltaAngle = a - b;
            if (deltaAngle > Math.PI) deltaAngle -= (float)(2 * Math.PI);
            if (deltaAngle > Math.PI) deltaAngle += (float)(2 * Math.PI);

            if (deltaAngle > 0.15) return 1;//a在b右边
            else if (deltaAngle < -0.15) return -1; //a在b左边
            else return 0;
        }
        public static bool AllEqual(int[] group, int value, int start, int end)//核对group数组从start到end元素与value相等
        {
            for (int i = start; i <= end; i++)
            {
                if (group[i] != value)
                {
                    if (value == 1 && group[i] == 2) //value==2是value==1的特殊情况
                    {
                        continue;
                    }
                    return false;
                }
            }
            return true;
        }
        public static void StopFish(ref Decision decision, int i)
        {
            decision.VCode = 0;
            decision.TCode = 7;
            timeForPoseToPose[i] = 0;
        }
        public static float GetVectorDistance(xna.Vector3 a, xna.Vector3 b)
        {
            return (float)Math.Sqrt((Math.Pow((a.X - b.X), 2d) + Math.Pow((a.Z - b.Z), 2d)));
        }
        public static void FishToPoint(ref Decision decisions, RoboFish fish, xna.Vector3 targetePoint, float targetDirection, int noOfFish, ref int[] timeForPoseToPose, int[] flag)
        {
            switch (flag[noOfFish])
            {
                case 0:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 250)
                        Helpers.Dribble(ref decisions, fish, targetePoint, targetDirection, 20f, 30f, 200, 14, 12, 15, 100, true);
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) > 130)
                    {
                        Helpers.PoseToPose(ref decisions, fish, targetePoint, targetDirection, 5f, 8f, 100, ref timeForPoseToPose[noOfFish]);
                    }
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) <= 130)
                    {
                        flag[noOfFish] = 1;
                    }
                    break;
                case 1:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 180)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) < 0)
                    {
                        decisions.TCode = 0;
                        decisions.VCode = 1;
                    }
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) > 0)
                    {
                        decisions.TCode = 15;
                        decisions.VCode = 1;
                    }
                    else
                    {
                        flag[noOfFish] = 2;
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                case 2:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 180) 
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) != 0)
                    {
                        flag[noOfFish] = 1;
                    }
                    else
                    {
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                default:
                    StopFish(ref decisions, noOfFish);
                    break;
            }
        }
        public static void FishToPointCircle(ref Decision decisions, RoboFish fish, xna.Vector3 targetePoint, float targetDirection, int noOfFish, ref int[] timeForPoseToPose, int[] flag)
        {
            switch (flag[noOfFish])
            {
                case 0:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 250)
                        Helpers.Dribble(ref decisions, fish, targetePoint, targetDirection, 20f, 30f, 200, 14, 12, 15, 100, true);
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) > 120)
                    {
                        Helpers.PoseToPose(ref decisions, fish, targetePoint, targetDirection, 5f, 60f, 100, ref timeForPoseToPose[noOfFish]);
                    }
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) <= 120)
                    {
                        flag[noOfFish] = 1;
                    }
                    break;
                case 1:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 180)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) < 0)
                    {
                        decisions.TCode = 0;
                        decisions.VCode = 1;
                    }
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) > 0)
                    {
                        decisions.TCode = 15;
                        decisions.VCode = 1;
                    }
                    else
                    {
                        flag[noOfFish] = 2;
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                case 2:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 180)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) != 0)
                    {
                        flag[noOfFish] = 1;
                    }
                    else
                    {
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                default:
                    StopFish(ref decisions, noOfFish);
                    break;
            }
        }
        public static void FishToPointLine(ref Decision decisions, RoboFish fish, xna.Vector3 targetePoint, float targetDirection, int noOfFish, ref int[] timeForPoseToPose, int[] flag)
        {
            switch (flag[noOfFish])
            {
                case 0:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 200)
                        Helpers.Dribble(ref decisions, fish, targetePoint, targetDirection, 20f, 30f, 200, 14, 12, 15, 100, true);
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) > 150)
                    {
                        Helpers.PoseToPose(ref decisions, fish, targetePoint, targetDirection, 15f, 60f, 100, ref timeForPoseToPose[noOfFish]);
                    }
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) <= 150)
                    {
                        flag[noOfFish] = 1;
                    }
                    break;
                case 1:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 180)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) < 0)
                    {
                        decisions.TCode = 0;
                        decisions.VCode = 1;
                    }
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) > 0)
                    {
                        decisions.TCode = 15;
                        decisions.VCode = 1;
                    }
                    else
                    {
                        flag[noOfFish] = 2;
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                case 2:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 180)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) != 0)
                    {
                        flag[noOfFish] = 1;
                    }
                    else
                    {
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                default:
                    StopFish(ref decisions, noOfFish);
                    break;
            }
        }
        public static void FishToPointQuick(ref Decision decisions, RoboFish fish, xna.Vector3 targetePoint, float targetDirection, int noOfFish, ref int[] timeForPoseToPose, int[] flag)
        {
            switch (flag[noOfFish])
            {
                case 0:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 200)
                        Helpers.Dribble(ref decisions, fish, targetePoint, targetDirection, 20f, 30f, 200, 14, 12, 15, 100, true);
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) > 150)
                    {
                        Helpers.PoseToPose(ref decisions, fish, targetePoint, targetDirection, 45f, 80f, 100, ref timeForPoseToPose[noOfFish]);
                    }
                    //  Helpers.PoseToPose(ref decisions, fish, targetePoint, targetDirection, 6f, 10f, 50, ref timeForPoseToPose[noOfFish]);
                    else if (GetVectorDistance(targetePoint, fish.PositionMm) <= 150)
                    {
                        flag[noOfFish] = 1;
                    }
                    break;
                case 1:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 200)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) < 0)
                    {
                        decisions.TCode = 0;
                        decisions.VCode = 1;
                    }
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) > 0)
                    {
                        decisions.TCode = 15;
                        decisions.VCode = 1;
                    }
                    else
                    {
                        flag[noOfFish] = 2;
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                case 2:
                    if (GetVectorDistance(targetePoint, fish.PositionMm) > 200)
                        flag[noOfFish] = 0;
                    else if (IsDirectionRight(targetDirection, fish.BodyDirectionRad) != 0)
                    {
                        flag[noOfFish] = 1;
                    }
                    else
                    {
                        StopFish(ref decisions, noOfFish);
                    }
                    break;
                default:
                    StopFish(ref decisions, noOfFish);
                    break;
            }
        }
        public static float CorrectRad(float angleToCorrect)
        {
            if (angleToCorrect > Math.PI)
                angleToCorrect -= 2 * (float)Math.PI;
            if (angleToCorrect < -Math.PI)
                angleToCorrect += 2 * (float)Math.PI;
            return angleToCorrect;
        }
        public static int completeCircle = 0;
        Decision[] preDecisions = null;
        private static int flag = 1;//主函数标志值
        private static int timeflag = 0;
        //以下声明量为标志量，通常情况下，2-10置0表示目标要调用PoseToPose或driible去目标点，1表示已到目标点（除前两个外）,2表示方向也正确
        private static int[] timeForPoseToPose = new int[11];
        private static bool complete = false;
        private static int[] startRoadflag = new int[11];
        private static int[] hillflag = new int[11];
        private static int[] oneflag = new int[11];
        private static int[] playflag = new int[11];
        private static int[] circleflag = new int[11];
        private static int[] oneHeartflag = new int[11];
        private static int[] smileFaceflag = new int[11];
        /// <summary>
        /// 获取当前仿真使命（比赛项目）当前队伍所有仿真机器鱼的决策数据构成的数组
        /// </summary>
        /// <param name="mission">服务端当前运行着的仿真使命Mission对象</param>
        /// <param name="teamId">当前队伍在服务端运行着的仿真使命中所处的编号 
        /// 用于作为索引访问Mission对象的TeamsRef队伍列表中代表当前队伍的元素</param>
        /// <returns>当前队伍所有仿真机器鱼的决策数据构成的Decision数组对象</returns>
        #region 开始路
        public static void StartRoad(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成开始路的目标点
            xna.Vector3 startRoad2 = new xna.Vector3(-780, 0, -954);
            xna.Vector3 startRoad3 = new xna.Vector3(-750, 0, 282);
            xna.Vector3 startRoad4 = new xna.Vector3(-60, 0, 834);
            xna.Vector3 startRoad5 = new xna.Vector3(588, 0, -984);
            xna.Vector3 startRoad6 = new xna.Vector3(-882, 0, -420);
            xna.Vector3 startRoad7 = new xna.Vector3(-810, 0, 972);
            xna.Vector3 startRoad8 = new xna.Vector3(492, 0, -402);
            xna.Vector3 startRoad9 = new xna.Vector3(594, 0, 954);
            xna.Vector3 startRoad10 = new xna.Vector3(660, 0, 202);
            xna.Vector3 startRoad42 = new xna.Vector3(-60, 0, -1200);
            #endregion
            #region 构成开始路的目标角度
            float SRD2 = (float)1.0472;
            float SRD3 = (float)1.0472;
            float SRD4 = (float)-1.5708;
            float SRD5 = (float)1.0472;
            float SRD6 = (float)2.0944;
            float SRD7 = (float)2.0944;
            float SRD8 = (float)2.0944;
            float SRD9 = (float)2.0944;
            float SRD10 = (float)1.0472;
            float SRD42 = (float)-1.5708;
            #endregion
            #region 一堆鱼移动到目标点和目标角度
            FishToPoint(ref decisions[1], fish2, startRoad2, SRD2, 2, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[2], fish3, startRoad3, SRD3, 3, ref timeForPoseToPose, startRoadflag);
            if(startRoadflag[0]==0)
                FishToPoint(ref decisions[3], fish4, startRoad4, SRD4, 4, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[4], fish5, startRoad5, SRD5, 5, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[5], fish6, startRoad6, SRD6, 6, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[6], fish7, startRoad7, SRD7, 7, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[7], fish8, startRoad8, SRD8, 8, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[8], fish9, startRoad9, SRD9, 9, ref timeForPoseToPose, startRoadflag);
            FishToPoint(ref decisions[9], fish10, startRoad10, SRD10, 10, ref timeForPoseToPose, startRoadflag);
            #endregion
            #region 进入下一阶段
            if (startRoadflag[0] == 0 && AllEqual(startRoadflag, 1, 2, 10)) 
            {
                startRoadflag[0] = 1;
                startRoadflag[4] = 0;
            }
            if (startRoadflag[0] == 1) 
            {
                FishToPointQuick(ref decisions[3], fish4, startRoad42, SRD42, 4, ref timeForPoseToPose, startRoadflag);
                startRoadflag[1] = 1;
            }
            if (startRoadflag[1] == 1 && (fish4.PositionMm.Z < -1100)) 
            {
                startRoadflag[0] = 2;
                StopFish(ref decisions[3], 4);
                complete = true;
            }
            #endregion
            #region 进入下一函数
            if (complete)
            {
                timeflag++;
                if (timeflag >= 30)//等待3s
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    timeflag = 0;
                    flag++;
                    complete = false;
                }
            }
            #endregion
        }
        #endregion
        #region 山字
        public static void HillCharacter(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            //StreamWriter log = new StreamWriter("C:\\Users\\wujun\\Desktop\\URWPGSim2D\\URWPGSim2D\\Strategy\\log.txt", true);
            //log.Write(AllEqual(hillflag, 1, 2, 10));
            //log.Write(' ');
            //log.WriteLine("end");
            //log.Close();
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成山字的目标点
            xna.Vector3 hill21 = new xna.Vector3(-1404, 0, 516);
            xna.Vector3 hill3 = new xna.Vector3(-726, 0, 570);
            xna.Vector3 hill4 = new xna.Vector3(108, 0, -702);
            xna.Vector3 hill5 = new xna.Vector3(108, 0, -156);
            xna.Vector3 hill6 = new xna.Vector3(108, 0, 534);
            xna.Vector3 hill7 = new xna.Vector3(-390, 0, 996);
            xna.Vector3 hill8 = new xna.Vector3(216, 0, 996);
            xna.Vector3 hill9 = new xna.Vector3(834, 0, 996);
            xna.Vector3 hill10 = new xna.Vector3(948, 0, 564);
            xna.Vector3 hill22 = new xna.Vector3(204, 0, -1122);
            xna.Vector3 hill23 = new xna.Vector3(1644, 0, 300);
            #endregion
            #region 构成山字的目标角度
            float HD21 = (float)-1.0472;
            float HD3 = (float)-1.5708;
            float HD4 = (float)-1.5708;
            float HD5 = (float)-1.5708;
            float HD6 = (float)-1.5708;
            float HD7 = 0;
            float HD8 = 0;
            float HD9 = 0;
            float HD10 = (float)-1.5708;
            float HD22 = (float)-0.5236;
            float HD23 = (float)0.4;
            #endregion
            #region 一堆鱼移动到目标点和目标角度
            if (hillflag[0] == 0)
                FishToPoint(ref decisions[1], fish2, hill21, HD21, 2, ref timeForPoseToPose, hillflag);
            FishToPoint(ref decisions[2], fish3, hill3, HD3, 3, ref timeForPoseToPose, hillflag);
            FishToPoint(ref decisions[3], fish4, hill4, HD4, 4, ref timeForPoseToPose, hillflag);
            FishToPoint(ref decisions[4], fish5, hill5, HD5, 5, ref timeForPoseToPose, hillflag);
            FishToPoint(ref decisions[5], fish6, hill6, HD6, 6, ref timeForPoseToPose, hillflag);
            FishToPointLine(ref decisions[6], fish7, hill7, HD7, 7, ref timeForPoseToPose, hillflag);
            FishToPointLine (ref decisions[7], fish8, hill8, HD8, 8, ref timeForPoseToPose, hillflag);
            FishToPointLine(ref decisions[8], fish9, hill9, HD9, 9, ref timeForPoseToPose, hillflag);
            FishToPoint(ref decisions[9], fish10, hill10, HD10, 10, ref timeForPoseToPose, hillflag);
            #endregion
            #region 山字第二阶段
            if (hillflag[0] == 0 && AllEqual(hillflag, 1, 3, 10) && hillflag[2] != 0)   //hillflag[2]只有0、1 、2三种可能性
            {
                hillflag[0] = 1;
                timeForPoseToPose[2] = 0;
            }
            if (hillflag[0] == 1)
                FishToPointQuick(ref decisions[1], fish2, hill22, HD22, 2, ref timeForPoseToPose, hillflag);
            if (hillflag[0] == 1 && (fish2.PositionMm.Z < -1000 && (fish2.PositionMm.X > -150 && fish2.PositionMm.X < 400))) 
            {
                hillflag[1] = 1;
                hillflag[0] = 3;
                timeForPoseToPose[2] = 0;
            }
            #endregion
            #region 山字第三阶段
            if (fish2.PositionMm.Z > 200) 
            {
                if (hillflag[1] == 1 && AllEqual(hillflag, 2, 3, 10))
                {
                    for (int i = 1; i < 11; i++)
                    {
                        hillflag[i] = 3;
                    }
                    StopFish(ref decisions[1], 2);
                }
            }
            if (hillflag[1] == 1)
                FishToPointQuick(ref decisions[1], fish2, hill23, HD23, 2, ref timeForPoseToPose, hillflag);
            #endregion
            #region 定住5s，进入下一函数
            if (hillflag[1] == 3)
            {
                timeflag++;
                if (timeflag >= 50)
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    flag++;
                    timeflag = 0;
                }
            }
            #endregion
        }
        #endregion
        #region 数字1
        public static void NumberOne(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成数字1的目标点
            xna.Vector3 one2 = new xna.Vector3(1000, 0, -900);
            xna.Vector3 one3 = new xna.Vector3(-195,0,-685);
            xna.Vector3 one4 = new xna.Vector3(108, 0, -702);
            xna.Vector3 one5 = new xna.Vector3(108, 0, -156);
            xna.Vector3 one6 = new xna.Vector3(108, 0, 534);
            xna.Vector3 one7 = new xna.Vector3(-390, 0, 996);
            xna.Vector3 one8 = new xna.Vector3(216, 0, 996);
            xna.Vector3 one9 = new xna.Vector3(834, 0, 984);
            xna.Vector3 one10 = new xna.Vector3(1266, 0, -444);
            #endregion
            #region 构成数字1的目标角度
            float OD2 = (float)-0.7854;
            float OD3 = (float)-0.7459;
            float OD4 = (float)-1.5708;
            float OD5 = (float)-1.5708;
            float OD6 = (float)-1.5708;
            float OD7 = 0;
            float OD8 = 0;
            float OD9 = 0;
            float OD10 = (float)1.0647;
            #endregion
            #region 一堆鱼移动到目标点和目标角度
            if (oneflag[2] == 0)
                FishToPoint(ref decisions[1], fish2, one2, OD2, 2, ref timeForPoseToPose, oneflag);
            FishToPoint(ref decisions[2], fish3, one3, OD3, 3, ref timeForPoseToPose, oneflag);
            FishToPointQuick(ref decisions[3], fish4, one4, OD4, 4, ref timeForPoseToPose, oneflag);
            FishToPointQuick(ref decisions[4], fish5, one5, OD5, 5, ref timeForPoseToPose, oneflag);
            FishToPointQuick(ref decisions[5], fish6, one6, OD6, 6, ref timeForPoseToPose, oneflag);
            FishToPointLine(ref decisions[6], fish7, one7, OD7, 7, ref timeForPoseToPose, oneflag);
            FishToPointLine(ref decisions[7], fish8, one8, OD8, 8, ref timeForPoseToPose, oneflag);
            FishToPointLine(ref decisions[8], fish9, one9, OD9, 9, ref timeForPoseToPose, oneflag);
            if (oneflag[10] == 0) 
                FishToPoint(ref decisions[9], fish10, one10, OD10, 10, ref timeForPoseToPose, oneflag);
            #endregion
            #region 定住6s，进入下一函数
            if (AllEqual(oneflag, 2, 3, 9))
            {
                complete = true;
            }
            if (complete)
            {
                for (int i = 1; i < 10; i++)
                {
                    decisions[i].TCode = 7;
                    decisions[i].VCode = 0;
                }
                timeflag++;
                if (timeflag >= 60)
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    flag++;
                    complete = false;
                    timeflag = 0;
                }
            }
            #endregion
        }
        #endregion
        #region 动态圆
        public static void MovingCircle(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成动态圆的目标点
            xna.Vector3 circle2 = new xna.Vector3(1080, 0, -324);
            xna.Vector3 circle3 = new xna.Vector3(546, 0, -888);
            xna.Vector3 circle4 = new xna.Vector3(-108, 0, -1014);
            xna.Vector3 circle5 = new xna.Vector3(-678, 0, -666);
            xna.Vector3 circle6 = new xna.Vector3(-900, 0, -66);
            xna.Vector3 circle7 = new xna.Vector3(474, 0, 948);
            xna.Vector3 circle8 = new xna.Vector3(-810, 0, 600);
            xna.Vector3 circle9 = new xna.Vector3(-288, 0, 1008);
            xna.Vector3 circle10 = new xna.Vector3(1050, 0, 378);
            #endregion
            #region 构成动态圆的目标角度
            float CD2 = (float)1.0472;
            float CD3 = (float)0.4363;
            float CD4 = (float)-0.2618;
            float CD5 = (float)-1.0472;
            float CD6 = (float)-1.5708;
            float CD7 = (float)2.618;
            float CD8 = (float)-2.2689;
            float CD9 = (float)-2.9674;
            float CD10 = (float)1.9199;
            #endregion
            #region 动态圆旋转
            if (completeCircle == 0) //未到达指定点
            {
                #region 一堆鱼移动到目标点和目标角度
                FishToPointCircle(ref decisions[1], fish2, circle2, CD2, 2, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[2], fish3, circle3, CD3, 3, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[3], fish4, circle4, CD4, 4, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[4], fish5, circle5, CD5, 5, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[5], fish6, circle6, CD6, 6, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[6], fish7, circle7, CD7, 7, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[7], fish8, circle8, CD8, 8, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[8], fish9, circle9, CD9, 9, ref timeForPoseToPose, circleflag);
                FishToPointCircle(ref decisions[9], fish10, circle10, CD10, 10, ref timeForPoseToPose, circleflag);
                #endregion
                #region 开始旋转
                if (AllEqual(circleflag, 2, 2, 10))
                {
                    completeCircle = 1;
                    for (int i = 0; i < 11; i++)//参数清零
                    {
                        circleflag[i] = 0;
                        timeForPoseToPose[i] = 0;
                    }
                }
            }
            if (completeCircle == 1)
            {
                timeflag++;
                for (int i = 1; i < 10; i++)
                {
                    decisions[i].TCode = 10;
                    decisions[i].VCode = 3;
                }
                if (timeflag >= 70)//旋转7s
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    timeflag = 0;
                    completeCircle = 2;
                }
            }
            if (completeCircle == 2)
            {
                timeflag++;
                for (int i = 1; i < 10; i++)
                {
                    decisions[i].TCode = 14;
                    decisions[i].VCode = 3;
                }
                if (timeflag >= 25)//旋转2.5s
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    timeflag = 0;
                    flag++;
                }
            }

            #endregion
        }
        #endregion

        #endregion
        #region 与黄鱼互动
        public static void PlayWithYellowFish(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish1 = mission.TeamsRef[teamId].Fishes[0];
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成与黄鱼互动的目标点
            xna.Vector3 play3 = new xna.Vector3(-1272, 0, -180);
            xna.Vector3 play4 = new xna.Vector3(-984, 0, 318);
            xna.Vector3 play5 = new xna.Vector3(-660, 0, 750);
            xna.Vector3 play6 = new xna.Vector3(30, 0, 758);
            xna.Vector3 play7 = new xna.Vector3(402, 0, 300);
            xna.Vector3 play8 = new xna.Vector3(804, 0, -174);
            xna.Vector3 play9 = new xna.Vector3(1212, 0, -582);
            xna.Vector3 play10 = new xna.Vector3(1566, 0, -990);
            xna.Vector3 center = new xna.Vector3(0, 0, 0);
            #endregion
            #region 构成与黄鱼互动的目标角度
            float PD3 = (float)-2.0944;
            float PD4 = (float)-2.0944;
            float PD5 = (float)-2.618;
            float PD6 = (float)-0.5836;
            float PD7 = (float)-0.8727;
            float PD8 = (float)-0.8727;
            float PD9 = (float)-0.8727;
            float PD10 = (float)-0.7854;
            #endregion
            #region 一堆鱼移动到目标点和目标角度
            FishToPoint(ref decisions[2], fish3, play3, PD3, 3, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[3], fish4, play4, PD4, 4, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[4], fish5, play5, PD5, 5, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[5], fish6, play6, PD6, 6, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[6], fish7, play7, PD7, 7, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[7], fish8, play8, PD8, 8, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[8], fish9, play9, PD9, 9, ref timeForPoseToPose, playflag);
            FishToPoint(ref decisions[9], fish10, play10, PD10, 10, ref timeForPoseToPose, playflag);
            //FishToPoint(ref decisions[1], fish2, fish1.PolygonVertices[4], fish1.BodyDirectionRad - (float)1.309, 2, ref timeForPoseToPose, playflag);
            Helpers.Dribble(ref decisions[1], fish2, fish1.PolygonVertices[3], CorrectRad(fish1.BodyDirectionRad - (float)1.0472), 30f, 20f, 100f, 14, 12, 15, 100, false);
            //float dir3 = xna.MathHelper.ToRadians(Helpers.GetAngleDegree(center - fish1.PositionMm));
            //Helpers.Dribble(ref decisions[1], fish2, fish1.PolygonVertices[0], dir3, 15, 30, 150, 14, 13, 15, 100, true);
            #endregion
            #region 到指定位置，进入下一函数
            if (AllEqual(playflag, 1, 3, 10))
            {
                complete = true;
            }
            if (complete)
            {
                timeflag++;
                if (timeflag >= 20)//等待2s
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    timeflag = 0;
                    flag++;
                    complete = false;
                }
            }
            #endregion
        }
        #endregion
        #region 一心
        public static void TheOneHeart(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成一心的目标点
            xna.Vector3 oneheart2 = new xna.Vector3(-1818, 0, 30);
            xna.Vector3 oneheart3 = new xna.Vector3(-1254, 0, 30);
            xna.Vector3 oneheart4 = new xna.Vector3(-636, 0, 30);
            xna.Vector3 oneheart5 = new xna.Vector3(624, 0, -108);
            xna.Vector3 oneheart6 = new xna.Vector3(1164, 0, -252);
            xna.Vector3 oneheart7 = new xna.Vector3(1338, 0, 48);
            xna.Vector3 oneheart8 = new xna.Vector3(1150, 0, 562);
            xna.Vector3 oneheart9 = new xna.Vector3(570, 0, 537);
            xna.Vector3 oneheart10 = new xna.Vector3(264, 0, -12);
            #endregion
            #region 构成一心的目标角度
            float OHD2 = 0;
            float OHD3 = 0;
            float OHD4 = 0;
            float OHD5 = (float)0.7854;
            float OHD6 = (float)-0.7854;
            float OHD7 = (float)-1.1305;
            float OHD8 = (float)-1.0229;
            float OHD9 = (float)-2.1876;
            float OHD10 = (float)-2.0316;
            #endregion
            #region 一堆鱼移动到目标点和目标角度
            FishToPointLine(ref decisions[1], fish2, oneheart2, OHD2, 2, ref timeForPoseToPose, oneHeartflag);
            FishToPointLine(ref decisions[2], fish3, oneheart3, OHD3, 3, ref timeForPoseToPose, oneHeartflag);
            FishToPointLine(ref decisions[3], fish4, oneheart4, OHD4, 4, ref timeForPoseToPose, oneHeartflag);
            FishToPoint(ref decisions[4], fish5, oneheart5, OHD5, 5, ref timeForPoseToPose, oneHeartflag);
            FishToPoint(ref decisions[5], fish6, oneheart6, OHD6, 6, ref timeForPoseToPose, oneHeartflag);
            FishToPoint(ref decisions[6], fish7, oneheart7, OHD7, 7, ref timeForPoseToPose, oneHeartflag);
            FishToPoint(ref decisions[7], fish8, oneheart8, OHD8, 8, ref timeForPoseToPose, oneHeartflag);
            FishToPoint(ref decisions[8], fish9, oneheart9, OHD9, 9, ref timeForPoseToPose, oneHeartflag);
            FishToPoint(ref decisions[9], fish10, oneheart10, OHD10, 10, ref timeForPoseToPose, oneHeartflag);
            #endregion
            #region 定住5s，进入下一函数
            if (AllEqual(oneHeartflag, 2, 2, 10))
            {
                complete = true;
            }
            if (complete)
            {
                for (int i = 1; i < 10; i++)
                    decisions[i].VCode = 0;
                timeflag++;
                if (timeflag >= 50)
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    timeflag = 0;
                    flag++;
                    complete = false;
                }
            }
            #endregion
        }
        #endregion
        #region 笑脸
        public static void SmileFace(ref Mission mission, int teamId, ref Decision[] decisions)
        {
            #region 声明变量
            int msPerCycle = mission.CommonPara.MsPerCycle;//仿真周期毫秒数
            #region 一堆鱼
            RoboFish fish1 = mission.TeamsRef[teamId].Fishes[0];
            RoboFish fish2 = mission.TeamsRef[teamId].Fishes[1];
            RoboFish fish3 = mission.TeamsRef[teamId].Fishes[2];
            RoboFish fish4 = mission.TeamsRef[teamId].Fishes[3];
            RoboFish fish5 = mission.TeamsRef[teamId].Fishes[4];
            RoboFish fish6 = mission.TeamsRef[teamId].Fishes[5];
            RoboFish fish7 = mission.TeamsRef[teamId].Fishes[6];
            RoboFish fish8 = mission.TeamsRef[teamId].Fishes[7];
            RoboFish fish9 = mission.TeamsRef[teamId].Fishes[8];
            RoboFish fish10 = mission.TeamsRef[teamId].Fishes[9];
            #endregion
            #endregion
            #region 构成笑脸的目标点
            xna.Vector3 smileface2 = new xna.Vector3(-480, 0, -330);
            xna.Vector3 smileface3 = new xna.Vector3(-246, 0, 774);
            xna.Vector3 smileface4 = new xna.Vector3(816, 0, -588);
            xna.Vector3 smileface5 = new xna.Vector3(1194, 0, -378);
            xna.Vector3 smileface6 = new xna.Vector3(-900, 0, -528);
            xna.Vector3 smileface7 = new xna.Vector3(-563, 0, 337);
            xna.Vector3 smileface8 = new xna.Vector3(438, 0, 768);
            xna.Vector3 smileface10 = new xna.Vector3(720, 0, 318);
            xna.Vector3 center = new xna.Vector3(0, 0, 0);
            #endregion
            #region 构成与黄鱼互动的目标角度
            float SFD2 = (float)0.7854;
            float SFD3 = (float)-2.6180;
            float SFD4 = (float)-1.0472;
            float SFD5 = (float)0.7854;
            float SFD6 = (float)-1.0472;
            float SFD7 = (float)-1.8148;
            float SFD8 = (float)0.5236;
            float SFD10 = (float)-1.2217;
            #endregion
            #region 一堆鱼移动到目标点和目标角度
            FishToPoint(ref decisions[1], fish2, smileface2, SFD2, 2, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[2], fish3, smileface3, SFD3, 3, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[3], fish4, smileface4, SFD4, 4, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[4], fish5, smileface5, SFD5, 5, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[5], fish6, smileface6, SFD6, 6, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[6], fish7, smileface7, SFD7, 7, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[7], fish8, smileface8, SFD8, 8, ref timeForPoseToPose, smileFaceflag);
            FishToPoint(ref decisions[9], fish10, smileface10, SFD10, 10, ref timeForPoseToPose, smileFaceflag);
            //FishToPoint(ref decisions[1], fish2, fish1.PolygonVertices[4], fish1.BodyDirectionRad - (float)1.309, 2, ref timeForPoseToPose, playflag);
            Helpers.Dribble(ref decisions[8], fish9, fish1.PolygonVertices[3], CorrectRad(fish1.BodyDirectionRad - (float)1.0472), 30f, 20f, 100f, 14, 12, 15, 100, false);
            //float dir3 = xna.MathHelper.ToRadians(Helpers.GetAngleDegree(center - fish1.PositionMm));
            //Helpers.Dribble(ref decisions[1], fish2, fish1.PolygonVertices[0], dir3, 15, 30, 150, 14, 13, 15, 100, true);
            #endregion
            #region 到指定位置，进入下一函数
            if (AllEqual(smileFaceflag, 2, 3, 10))
            {
                complete = true;
            }
            if (complete)
            {
                timeflag++;
                if (timeflag >= 40)//等待4s
                {
                    for (int i = 0; i < 11; i++)
                        timeForPoseToPose[i] = 0;
                    timeflag = 0;
                    flag++;
                    complete = false;
                }
            }
            #endregion
        }
        #endregion

        public Decision[] GetDecision(Mission mission, int teamId)
        {
            // 决策类当前对象第一次调用GetDecision时Decision数组引用为null
            if (decisions == null)
            {// 根据决策类当前对象对应的仿真使命参与队伍仿真机器鱼的数量分配决策数组空间
                decisions = new Decision[mission.CommonPara.FishCntPerTeam];
                preDecisions = new Decision[mission.CommonPara.FishCntPerTeam];
            }
            mission.CommonPara.MsPerCycle = 100;
            #region 决策计算过程 需要各参赛队伍实现的部分
            #region 策略编写帮助信息
            //====================我是华丽的分割线====================//
            //======================策略编写指南======================//
            //1.策略编写工作直接目标是给当前队伍决策数组decisions各元素填充决策值
            //2.决策数据类型包括两个int成员，VCode为速度档位值，TCode为转弯档位值
            //3.VCode取值范围0-14共15个整数值，每个整数对应一个速度值，速度值整体但非严格递增
            //有个别档位值对应的速度值低于比它小的档位值对应的速度值，速度值数据来源于实验
            //4.TCode取值范围0-14共15个整数值，每个整数对应一个角速度值
            //整数7对应直游，角速度值为0，整数6-0，8-14分别对应左转和右转，偏离7越远，角度速度值越大
            //5.任意两个速度/转弯档位之间切换，都需要若干个仿真周期，才能达到稳态速度/角速度值
            //目前运动学计算过程决定稳态速度/角速度值接近但小于目标档位对应的速度/角速度值
            //6.决策类Strategy的实例在加载完毕后一直存在于内存中，可以自定义私有成员变量保存必要信息
            //但需要注意的是，保存的信息在中途更换策略时将会丢失
            //====================我是华丽的分割线====================//
            //=======策略中可以使用的比赛环境信息和过程信息说明=======//
            //场地坐标系: 以毫米为单位，矩形场地中心为原点，向右为正X，向下为正Z
            //            负X轴顺时针转回负X轴角度范围为(-PI,PI)的坐标系，也称为世界坐标系
            //mission.CommonPara: 当前仿真使命公共参数
            //mission.CommonPara.FishCntPerTeam: 每支队伍仿真机器鱼数量
            //mission.CommonPara.MsPerCycle: 仿真周期毫秒数
            //mission.CommonPara.RemainingCycles: 当前剩余仿真周期数
            //mission.CommonPara.TeamCount: 当前仿真使命参与队伍数量
            //mission.CommonPara.TotalSeconds: 当前仿真使命运行时间秒数
            //mission.EnvRef.Balls: 
            //当前仿真使命涉及到的仿真水球列表，列表元素的成员意义参见URWPGSim2D.Common.Ball类定义中的注释
            //mission.EnvRef.FieldInfo: 
            //当前仿真使命涉及到的仿真场地，各成员意义参见URWPGSim2D.Common.Field类定义中的注释
            //mission.EnvRef.ObstaclesRect: 
            //当前仿真使命涉及到的方形障碍物列表，列表元素的成员意义参见URWPGSim2D.Common.RectangularObstacle类定义中的注释
            //mission.EnvRef.ObstaclesRound:
            //当前仿真使命涉及到的圆形障碍物列表，列表元素的成员意义参见URWPGSim2D.Common.RoundedObstacle类定义中的注释
            //mission.TeamsRef[teamId]:
            //决策类当前对象对应的仿真使命参与队伍（当前队伍）
            //mission.TeamsRef[teamId].Para:
            //当前队伍公共参数，各成员意义参见URWPGSim2D.Common.TeamCommonPara类定义中的注释
            //mission.TeamsRef[teamId].Fishes:
            //当前队伍仿真机器鱼列表，列表元素的成员意义参见URWPGSim2D.Common.RoboFish类定义中的注释
            //mission.TeamsRef[teamId].Fishes[i].PositionMm和PolygonVertices[0],BodyDirectionRad,VelocityMmPs,
            //                                   AngularVelocityRadPs,Tactic:
            //当前队伍第i条仿真机器鱼鱼体矩形中心和鱼头顶点在场地坐标系中的位置（用到X坐标和Z坐标），鱼体方向，速度值，
            //                                   角速度值，决策值
            //====================我是华丽的分割线====================//
            //========================典型循环========================//
            //for (int i = 0; i < mission.CommonPara.FishCntPerTeam; i++)
            //{
            //  decisions[i].VCode = 0; // 静止
            //  decisions[i].TCode = 7; // 直游
            //}
            //====================我是华丽的分割线====================//
            #endregion

            #endregion
            if (flag == 1)
                HillCharacter(ref mission, teamId, ref decisions);

            if (flag == 2)
                NumberOne(ref mission, teamId, ref decisions);

            if (flag == 3)
                MovingCircle(ref mission, teamId, ref decisions);

            if (flag == 4)
                TheOneHeart(ref mission, teamId, ref decisions);

            if (flag == 5)
                PlayWithYellowFish(ref mission, teamId, ref decisions);

            if (flag == 6)
                StartRoad(ref mission, teamId, ref decisions);

            if (flag == 7)
                SmileFace(ref mission, teamId, ref decisions);

            if(flag==8)
            {
                for (int i = 2; i <= 10; i++)
                {
                    StopFish(ref decisions[i - 1], i);
                }
            }
            return decisions;
        }
    }









