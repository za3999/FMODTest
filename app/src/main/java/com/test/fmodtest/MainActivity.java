package com.test.fmodtest;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import org.fmod.FMOD;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void test(View view) {
        FModUtil.ins(getApplicationContext()).changeVoices(0, "file:///android_asset/derry.mp3",
                () -> Toast.makeText(MainActivity.this, "finish", Toast.LENGTH_SHORT).show());
    }
}