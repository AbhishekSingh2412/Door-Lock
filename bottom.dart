import 'package:flutter/material.dart';
import 'Constants.dart';
class BottomButton extends StatelessWidget {
  final Function onTap;
  final String buttonTitle;
  BottomButton({@required this.onTap,@required this.buttonTitle});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onTap,

      child: Container(
//                padding: EdgeInsets.only(bottom: 5.0),
        color: Colors.lightBlueAccent,
        margin: EdgeInsets.only(top: 10.0),
        width: double.infinity,
        height: 50.0 ,
        child: Center(child: Text(buttonTitle,style: klargeButtontextStyle)),
      ),
    );
  }
}
