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
$team = utf8_decode($_POST['newTeam']);
/*--------------------------------------------------------------------*/

/*--------------------METIENDO DATOS A LA BASE DE DATOS--------------------*/

$Sql='INSERT INTO TEAMS(TEAMNAME) VALUES(' . '"'. $team . '"' . ')';

mysql_query($Sql, $conexion) or die(mysql_error());
header("Location: ./gamer.php"); 
?>
