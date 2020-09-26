import info.gridworld.actor.ActorWorld;
import info.gridworld.actor.Bug;
import info.gridworld.actor.Flower;
import info.gridworld.actor.Rock;
import info.gridworld.grid.Location;
import info.gridworld.actor.Actor;
import info.gridworld.grid.Grid;
import java.awt.*;
public class JumperBug extends Bug{
    private int moves;
    private double movemax;
    public JumperBug(Color color){
        super.setColor(color);
    }
    public JumperBug(){
    }
    public void jump()
  {
    Grid<Actor> gr = getGrid();
    if (gr == null)
      return;
    Location loc = getLocation();
    Location next = loc.getAdjacentLocation(getDirection());
    Location twoAway = next.getAdjacentLocation(getDirection());
    if (gr.isValid(next)){
      moveTo(twoAway);
    }
      Flower flower = new Flower(getColor());
      flower.putSelfInGrid(gr, loc);
}
public void act(){
        if(canMove()){
            move();
        }
        else if(canJump()){
            jump();
        }
        else{
            turn();
        }
    }
public boolean canJump()
  {
    Grid<Actor> gr = getGrid();
    if (gr == null)
      return false;
    Location loc = getLocation();
    Location next = loc.getAdjacentLocation(getDirection());
    if (!gr.isValid(next))
return false;
Actor neighbor = gr.get(next);
return (neighbor == null) || (neighbor instanceof Rock); // ok to move into empty location or onto flower
// not ok to move onto any other actor
}
}