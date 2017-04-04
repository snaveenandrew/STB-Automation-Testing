package com.testing.process;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

import org.apache.log4j.Logger;
import org.apache.log4j.PropertyConfigurator;
import org.json.JSONObject;

import com.testing.util.VideoUtil;

public class VideoProcessor {
	static Logger logger = Logger.getLogger(VideoProcessor.class);
	public static JSONObject DetectVideo() throws IOException {
		Properties prop=new Properties();
		InputStream input = new FileInputStream("E:\\Final year project\\Function\\config\\config.properties");
		prop.load(input);
		PropertyConfigurator.configure(prop.getProperty("LOGGER_PATH"));
		logger.info("Video Detection Service Started...");
		return VideoUtil.DetectVideo();
	}
}
