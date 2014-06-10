package com.example.hello_jni;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		int result = nativeTest(3, 4);
		Toast.makeText(this, "" + result, Toast.LENGTH_SHORT).show();
		return true;
	}
	
    static {
        System.loadLibrary("hello-jni");
    }
    
    public native int nativeTest(int a, int b);
}
