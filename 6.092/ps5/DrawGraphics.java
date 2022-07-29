import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class DrawGraphics {
	ArrayList<BouncingBox> boxes = new ArrayList<BouncingBox>();

	/** Initializes this class for drawing. */
	public DrawGraphics() {
		boxes.add(new BouncingBox(200, 50, Color.RED));
		boxes.add(new BouncingBox(100, 50, Color.BLUE));
		boxes.add(new BouncingBox(0, 50, Color.GREEN));
		boxes.get(0).setMovementVector(3, 0);
		boxes.get(1).setMovementVector(0, 3);
		boxes.get(2).setMovementVector(3, 3);
	}

	/** Draw the contents of the window on surface. Called 20 times per second. */
	public void draw(Graphics surface) {
		//surface.drawLine(0, 250, 300, 250);
		//surface.drawRect(50,100,200,150);
		for(BouncingBox box: boxes) {
			box.draw(surface);
		}
		//int[] x = {150,50,250};
		//int[] y = {10, 100,100};
 		//surface.drawPolygon(x,y,3);
 		//surface.fillArc(100,200,100,100,0,180);
	}
}
