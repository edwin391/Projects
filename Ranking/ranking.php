<?php
$host     = "localhost";
$user     = "root";
$password = "jair.gandallin";
$db = "NCGA";
$conexion=mysql_connect($host,$user,$password) or die ("Problemas con servidor");
mysql_select_db($db,$conexion) or die("Base de datos en mantenimiento");

$usuario = utf8_decode($_GET['usuario']);

?>      
<html>
  <body>

    <?php
      $selectUsuario=mysql_query('SELECT GAMER_TAG, sum(SCORE) as suma FROM RANKING where GAME="Halo" group by GAMER_TAG;
', $conexion) or die(mysql_error());
      echo "<h1>GAMERS OF HALO</h1><br>";
      
      $i=0;
      $resultado = mysql_num_rows($selectUsuario);

      for($i=0;$i<$resultado;$i++){
		$f=mysql_fetch_array($selectUsuario);
		$suma = $f['suma'];
		$newSuma[] = array('score' => $suma, 'gamer_tag' => $f['GAMER_TAG']);
      }

      foreach ($newSuma as $key => $row) {
        $auxiliar[$key] = $row['score'];
      }

      array_multisort($auxiliar, SORT_DESC, $newSuma);
      
      $lugar=1;
      foreach ($newSuma as $key => $row) {
        echo '<a href="mostrar.php?usuario='.$f[GAMER_TAG].'">'.$lugar.'.- '.$row['gamer_tag'].' -> score: '.$row['score'].'</a><br>';
        $lugar++;
      }  

    ?>

<!--////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////-->

    <?php
	$selectUsuario1=mysql_query('SELECT GAMER_TAG, sum(SCORE) as suma FROM RANKING where GAME="Call of Duty" group by GAMER_TAG;
', $conexion) or die(mysql_error());
      echo "<h1>GAMERS OF CALL OF DUTY</h1><br>";
      
      $i1=0;
      $resultado1 = mysql_num_rows($selectUsuario1);

      for($i1=0;$i1<$resultado1;$i1++){
		$f1=mysql_fetch_array($selectUsuario1);
		$suma1 = $f1['suma'];
		$newSuma1[] = array('score' => $suma1, 'gamer_tag' => $f1['GAMER_TAG']);
      }

      foreach ($newSuma1 as $key1 => $row1) {
        $auxiliar1[$key1] = $row1['score'];
      }

      array_multisort($auxiliar1, SORT_DESC, $newSuma1);
      
      $lugar1=1;
      foreach ($newSuma1 as $key1 => $row1) {
        echo '<a href="mostrar.php?usuario='.$f1[GAMER_TAG].'">'.$lugar1.'.- '.$row1['gamer_tag'].' -> score: '.$row1['score'].'</a><br>';
        $lugar1++;
      }  
    ?>

  </body>
</html>