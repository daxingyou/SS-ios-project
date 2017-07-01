package com.tongqu.client.jinhua;

import android.app.Application;

public class GameApplication extends Application {

	private static GameApplication instance;

	public static final String PackName = "com.tongqu.client.jinhua";
	public static final String APP_NAME = "jinhua";
	public static final int GAME_ID = 1;

	public static GameApplication getInstance() {
		return instance;
	}

	@Override
	public void onCreate() {
		super.onCreate();

		instance = this;

	}

}
