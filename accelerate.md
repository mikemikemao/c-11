[toc]

# 2022年积累

### 1.Android 执行命令行；打开RK网络adb

```java
public void onClickOpenADB(View view){
    try {
        Process process =Runtime.getRuntime().exec("setprop persist.internet.adb.enable 1");
        InputStreamReader ir = new InputStreamReader(process.getInputStream());
        BufferedReader input = new BufferedReader(ir);
        String str = null;
        while ((str=input.readLine())!=null){
            Log.d(TAG,"testprop = "+str);
        }
    } catch (IOException e) {
        e.printStackTrace();
        Log.d(TAG,e.getMessage());
    }
}
```

