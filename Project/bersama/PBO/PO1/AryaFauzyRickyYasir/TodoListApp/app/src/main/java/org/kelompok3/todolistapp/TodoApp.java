package org.kelompok3.todolistapp;

import android.app.Application;
import com.jakewharton.threetenabp.AndroidThreeTen;

public class TodoApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        AndroidThreeTen.init(this);
    }
}

