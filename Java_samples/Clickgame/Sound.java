import javax.swing.JApplet;
import java.applet.*;
public class Sound{
    private AudioClip clip;
    public Sound(String fileName){
        clip = Applet.newAudioClip( getClass().getResource( fileName));
    
    }
    public void play(){
        clip.play();
    }
    
    public void stop(){
        clip.stop();
    }
    public void loop(){
        clip.loop();
    }
}