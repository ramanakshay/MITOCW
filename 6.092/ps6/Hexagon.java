import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;

public class Hexagon implements Sprite {
	private Color color;
	private int sideLength;

	public Hexagon(int sideLength, Color color) {
		this.color = color;
		this.sideLength = sideLength;
	}

	public void draw(Graphics surface, int x, int y) {
		int[] xCoordinates = { (int) (x),
				(int) (x + sideLength / 2.0),
				(int) (x + 3 * sideLength / 2.0),
				(int) (x + 2 * sideLength),
				(int) (x + 3 * sideLength / 2.0),
				(int) (x + sideLength / 2.0) };
		int[] yCoordinates = { (int) (y + sideLength * Math.sqrt(3.0) / 2.0),
				(int) (y),
				(int) (y),
				(int) (y + sideLength * Math.sqrt(3.0) / 2.0),
				(int) (y + sideLength * Math.sqrt(3.0)),
				(int) (y + sideLength * Math.sqrt(3.0)),
				};
		surface.setColor(color);
		surface.fillPolygon(xCoordinates, yCoordinates, 6);
		surface.setColor(Color.BLACK);
		((Graphics2D) surface).setStroke(new BasicStroke(3.0f));
		surface.drawPolygon(xCoordinates, yCoordinates, 6);
	}

	public int getWidth() {
		return 2 * sideLength;
	}

	public int getHeight() {
		return (int) (Math.sqrt(3.0) * sideLength);
	}
}
