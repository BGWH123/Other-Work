import 'package:flutter/material.dart';
void main()=>runApp(myApp());
class myApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Text widget',
      home: Scaffold(
        body: Center(
            child: Container(
                child: new Image.network(
                    'https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE4wwuo?ver=7f01',

                  repeat: ImageRepeat.repeatY,
                ),
              width: 300.0,
              height: 200.0,
              color: Colors.lightBlue,
            )
        ),
      ),
    );
  }
}
