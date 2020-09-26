import javax.swing.*;
import java.awt.*;
public class GameDriver{
    
    public static void main(String[] args){
        
        JFrame frame = new JFrame("Baby Blast");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocation(200,200);
        
        Game game = new Game();
        
        frame.getContentPane().add(game);
        frame.pack();
        frame.setVisible(true);
        game.go();
    }
}