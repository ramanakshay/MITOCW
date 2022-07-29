import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

public class DrawGraphics {
    ArrayList<Mover> objects = new ArrayList<Mover>();

    /** Initializes this class for drawing. */
    public DrawGraphics() {
        Rectangle ob1 = new Rectangle(15, 20, Color.RED);
        objects.add(new Bouncer(100, 170, ob1));
        objects.get(0).setMovementVector(3, 1);
        Hexagon ob2 = new Hexagon(15, Color.BLUE);
        objects.add(new Bouncer(100, 170, ob2));
        objects.get(1).setMovementVector(-3,-1);
        Rectangle ob3 = new Rectangle(15, 20, Color.RED);
        objects.add(new StraightMover(0, 150, ob3));
        objects.get(2).setMovementVector(3, 0);
        Hexagon ob4 = new Hexagon(15, Color.BLUE);
        objects.add(new StraightMover(150, 150, ob4));
        objects.get(3).setMovementVector(3,3);
    }

    /** Draw the contents of the window on surface. */
    public void draw(Graphics surface) {
    	for(Mover object: objects) {
    		object.draw(surface);
    	}
    }
}
