package org.credil.helloworldservice;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;

/**
 * Created by IntelliJ IDEA.
 * User: kejo
 * Date: 5/31/11
 * Time: 6:33 PM
 * To change this template use File | Settings | File Templates.
 */
public class HelloWorldService extends Service {
    public IBinder onBind(Intent intent) {
        return null;
    }
}
