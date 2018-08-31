<?php
        $mydb=new mysqli("localhost","root","pass","nodemcu") or die("-1");
        $motion=$_GET['state'];
        $cmd="INSERT INTO motionData(motion) VALUES($motion)";
        if($mydb->query($cmd))
                echo 1;
        else
                echo 0;
?>
