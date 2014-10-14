import java.util.HashSet;

import arduino.ArduinoImpl;

import play.cache.Cache;
import play.jobs.*;
import models.*;
import play.*;
import play.test.*;
 
@OnApplicationStart
public class Bootstrap extends Job {
    
    public void doJob() {    	
		String PORT_NAMES[] = { 
			"/dev/tty.usbserial-A9007UX1", // Mac OS X
			"/dev/ttyUSB0", // Linux
			"COM4", "COM3", "COM2", "COM1", "COM6" // Windows
		};
		ArduinoImpl arduino = new ArduinoImpl(PORT_NAMES);
		arduino.initialize();
		ArduinoImpl.current = arduino;	
		
    }
    
}