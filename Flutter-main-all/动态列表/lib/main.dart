import 'package:flutter/material.dart';

void main()=>runApp(MyApp(
  items:List<String>.generate(1000, (i) =>"我爱卢佳 $i")
));
class MyApp extends StatelessWidget {
  final List <String>items;
  MyApp({Key?key,required this.items}):super(key: key);
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'YH FLUtter Demo',
      home: Scaffold(
        appBar: new AppBar(title: new Text('ListView Widget')),
        body: new ListView.builder(
          itemCount: 1000,
          itemBuilder: (context, index) {
            return new ListTile(
                title: new Text('${items[index]}')
            );
          },
        ),
      ),
    );
  } //Image
}