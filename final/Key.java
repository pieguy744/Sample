//Key Class
import java.util.ArrayList;
import java.util.List;
import java.io.*;
import java.awt.*;
public class Key extends Cube{
    private int xPos,yPos; 
    private int xSize,ySize;
    private Color color;
    private boolean done;
    public Key(int a, int b, int c, int d, Color e){
        super(a,b,c,d);
        super.setColor(e);
    }
    public void reset(){
        done = false;
    }
      public boolean collide()
    {
        if(done || (Game.player.getLeft() < super.getX() + super.getxSize() && Game.player.getRight() > super.getX() && Game.player.getTop() < super.getY() + super.getySize() && Game.player.getBottom() > super.getY()))
        {
            if(!done)
            Game.holmTaunt.get((int)(Math.random()*Game.holmTaunt.size())).play();
            done = true;
            return true;
        }
        return false;
    }
}