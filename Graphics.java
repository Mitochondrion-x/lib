package five;

import java.awt.Color;
import java.awt.Container;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class Graphics {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		JFrame jf = new JFrame();
		Container cc= jf.getContentPane();
		cc.setBackground(Color.white);
		jf.setSize(960,630);
		jf.setLocation(500,200);
		jf.setTitle("Gobang");
		
		JLabel jl = new JLabel("this is a test Jframe");
		jl.setHorizontalAlignment(SwingConstants.CENTER);
		
		cc.add(jl);
		
		jf.setVisible(true);
		
	}
}