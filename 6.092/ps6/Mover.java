import java.awt.Graphics;

public interface Mover {
	
	/** Starts moving the object in the direction (xIncrement, yIncrement). */
	void setMovementVector(int xIncrement, int yIncrement);
	
	 /** Draws the sprite at its current position on to surface. */
	void draw(Graphics surface);
	
}
