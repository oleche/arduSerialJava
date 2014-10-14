package controllers;

import play.*;
import play.i18n.Lang;
import play.mvc.*;

import java.util.*;

import arduino.ArduinoImpl;

import models.*;


public class Arduino extends Controller {
	public static void on(){
		ArduinoImpl.current.on();
	}
	
	public static void off(){
		ArduinoImpl.current.off();
	}
	
	public static void status(){
		ArduinoImpl.current.status();
	}
}
