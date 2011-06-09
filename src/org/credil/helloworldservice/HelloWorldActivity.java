package org.credil.helloworldservice;

import android.app.Activity;
import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.util.Log;
import android.widget.TextView;

/**
 * Sample client using purely public Android interfaces
 */
public class HelloWorldActivity extends Activity {
    private static final String LOG_TAG = HelloWorldActivity.class.getSimpleName();

    TextView mHelloBox;
    IHelloWorld mIHelloWorld;

    public ServiceConnection serviceConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName name, IBinder service) {
            Log.d(LOG_TAG, "Service connected");
            mIHelloWorld = IHelloWorld.Stub.asInterface(service);
            mHelloBox.append("connected\n");
            try {
                mIHelloWorld.hellothere("Calling from Java");
            } catch (RemoteException e) {
                Log.w(LOG_TAG," Failed to invoke hellothere:" + e.getMessage(),e);
            }
        }

        public void onServiceDisconnected(ComponentName name) {
            mHelloBox.append("diconnected\n");
            Log.e(LOG_TAG, "disconnected");
            //This is where the current story ends. once disconnected we are not able to automatically reconnect
            mIHelloWorld = null;
        }
    };

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.hello);

        mHelloBox = (TextView) findViewById(R.id.HelloView01);
        mHelloBox.setText("start\n");


        //We can currently not perform a bindService because the native code
        //did not register to the activity manager
        bindService(new Intent("org.credil.helloworldservice.IHelloWorld"),serviceConnection, BIND_AUTO_CREATE);
    }

    public void onDestroy(){
        super.onDestroy();
        unbindService(serviceConnection);
    }
}