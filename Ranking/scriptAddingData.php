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
$kill = utf8_decode($_POST['kill']);
$death = utf8_decode($_POST['death']);
$score = utf8_decode($_POST['score']);
$minutes = utf8_decode($_POST['minutes']);
$game = utf8_decode($_POST['game']);
$match = utf8_decode($_POST['match']);
$place = utf8_decode($_POST['place']);

$data1tag = utf8_decode($_POST['tagnew']);
$data2tag = utf8_decode($_POST['tag']);

if ($data1tag==NULL){
	$tag=$data2tag;
}else{
	$tag=$data1tag;
}

if($match=="Hardpoint"){
 $killscore=$kill*100;
}elseif ($match=="Search and Destroy") {
 $killscore=$kill*500;
}elseif ($match=="Uplink") {
 $killscore=$kill*100;
}elseif ($match=="Breakout") {

}elseif ($match=="Capture the flag") {

}elseif ($match=="Stronghold") {

}

$date=date('m-d-Y');

$checkUSER = "SELECT GAMER_TAG FROM RANKING WHERE GAMER_TAG='".$tag."' ";
$check = mysql_query($checkUSER, $conexion) or die(mysql_error());				
$num_rows = mysql_num_rows($check);

/*--------------------Precesamioento de datos--------------------*/
$killDeath=($kill/$death);
$scorePerMinute=($score/$minutes);
/*--------------------------------------------------------------------*/

if($num_rows != 0)
  {
    ?>
    <meta charset="utf-8">
    <script>
      window.location.href='./gamer.php';
      alert('This gamer already exist, and it was added to his/her team');
    </script>
    <?php
    /*--------------------SELECCIONAMOS EQUIPO EN EL CUAL SE ENCUENTRA AGREGADO--------------------*/
    $selectUsuario=mysql_query("SELECT TEAM FROM RANKING WHERE GAMER_TAG='".$tag."' ", $conexion) or die(mysql_error());
    $sesion=mysql_fetch_array($selectUsuario);
    $gamersteam=$sesion['TEAM'];
    /*--------------------------------------------------------------------*/
    /*--------------------METIENDO DATOS A LA BASE DE DATOS--------------------*/

    $Sqlexist='INSERT INTO RANKING(GAMER_TAG, KILL_DEATH, SCORE_PER_MINUTE, PREVIOUS_PLACE, MATCH_TYPE, GAME, DATE, TEAM, DEATH, WINS, SCORE, KILLSCORE) VALUES(
			' . '"'. $tag . '"' . ',
			' .$killDeath. ',
			' .$scorePerMinute. ',
			' .$place. ',
			' . '"'. $match . '"' . ',
			' . '"'. $game . '"' . ',
			' . '"'. $date . '"' . ',
			' . '"'. $gamersteam . '"' . ',
			' .$death. ',
			' .$kill. ',
			' .$score. ',
			' .$killscore. ')';
    mysql_query($Sqlexist, $conexion) or die(mysql_error());
    /*--------------------------------------------------------------------*/
  }
  else
  {
    ?>
    <meta charset="utf-8">
    <script>
      window.location.href='./gamer.php';
      alert('This is a new gamer');
    </script>
    <?php
    /*--------------------METIENDO DATOS A LA BASE DE DATOS--------------------*/

    $Sqlnew='INSERT INTO RANKING(GAMER_TAG, KILL_DEATH, SCORE_PER_MINUTE, PREVIOUS_PLACE, MATCH_TYPE, GAME, DATE, TEAM, DEATH, WINS, SCORE) VALUES(
			' . '"'. $tag . '"' . ',
			' .$killDeath. ',
			' .$scorePerMinute. ',
			' .$place. ',
			' . '"'. $match . '"' . ',
			' . '"'. $game . '"' . ',
			' . '"'. $date . '"' . ',
			"NOTEAM",
			' .$death. ',
			' .$kill. ',
			' .$score. ' )';
    mysql_query($Sqlnew, $conexion) or die(mysql_error());
    /*--------------------------------------------------------------------*/
  }
?>
