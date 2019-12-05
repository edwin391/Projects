<?php
/*--------------------CONEXION A BASE DE DATOS-----------------------*/
$host     = "localhost";
$user     = "root";
$password = "jair.gandallin";
$db = "NCGA";
$conexion=mysql_connect($host,$user,$password) or die ("Problemas con servidor");

mysql_select_db($db,$conexion) or die("Base de datos en mantenimiento");
/*--------------------------------------------------------------------*/

/*--------------------RECIBIENDO DATOS-----------------------*/
$team = utf8_decode($_POST['teamadding']);
$name = utf8_decode($_GET['name']);
/*--------------------------------------------------------------------*/

/*--------------------METIENDO DATOS A LA BASE DE DATOS--------------------*/

$Sql='UPDATE RANKING set TEAM="'.$team.'" WHERE GAMER_TAG="'.$name.'"';

mysql_query($Sql, $conexion) or die(mysql_error());
header("Location: ./gamer.php"); 
?>
