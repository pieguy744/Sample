import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.awt.image.*;
import java.util.ArrayList;
public class GameDriver{
    
    public static void main(String[] args){
        JFrame frame = new JFrame("The HolmMAZING Race");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocation(200,200);
        
        Game game = new Game();
        
        frame.getContentPane().add(game);
        frame.pack();
        frame.setVisible(true);
        game.go();
    }
}