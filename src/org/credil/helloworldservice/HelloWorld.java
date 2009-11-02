package org.credil.helloworldservice;

import org.credil.helloworldservice.R;
import android.app.Activity;
import android.content.Context;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.util.Log;
import android.widget.TextView;

public class HelloWorld extends Activity {

    public HelloWorldServiceInterface hws;
    public TextView helloBox;
    public ServiceConnection serviceConnection;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.hello);

        helloBox = (TextView)findViewById(R.id.HelloView01);
        helloBox.setText("start");

        serviceConnection = new ServiceConnection() {
            public void onServiceConnected(ComponentName name, IBinder service) {
                Log.e("HelloWorld", "Service connected");
                hws = HelloWorldServiceInterface.Stub.asInterface(service);
                if(hws != null) {
                    helloBox.setText("connected");
                    Log.e("HelloWorld", "Connected");
                } else {
                    Log.e("HelloWorld", "Failed to connect");
                }
            }  

            public void onServiceDisconnected(ComponentName name) {
                Log.e("HelloWorld","disconnected");
                hws = null;
            }
        };

        bindService(new Intent("org.credil.helloworldservice.HelloWorldServiceInterface.START_SERVICE"),
                    serviceConnection, Context.BIND_AUTO_CREATE);
    }
}