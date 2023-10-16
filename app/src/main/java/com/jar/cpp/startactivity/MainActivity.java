package com.jar.cpp.startactivity;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.jar.cpp.startactivity.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'startactivity' library on application startup.
    static {
        System.loadLibrary("startactivity");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        initEvent();
    }

    private void initEvent() {
        binding.btnStart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                enterTarget();
            }
        });

        binding.btnAlone.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                testOne("人生之无奈");
            }
        });



    }


    public native void enterTarget();
    public native void testOne(String temp);
}