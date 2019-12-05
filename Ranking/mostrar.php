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
    <h1>GAMER: <?php echo $usuario; ?></h1>
    <table border="1" style="width:70%">

        <tr>
          <th>TEAM</th>
          <th>KILLS</th>
          <th>KILL SCORE</th>
          <th>NON-KILL SCORE</th>
          <th>DEATHS</th>
          <th>KILL/DEATH</th>
          <th>TOTAL SCORE</th>
          <th>SCORE PER MINUTE</th>
          <th>PREVIOUS PLACE</th>
          <th>MATCH TYPE</th>
          <th>GAME</th>
          <th>DATE</th>
        </tr>
        
        <?php
          $sumaKD=0;
          $sumaresultado=0;
          $sumaSPM=0;
          $selectUsuario=mysql_query("SELECT * FROM RANKING WHERE GAMER_TAG='".$usuario."'", $conexion) or die(mysql_error());
          while($f=mysql_fetch_array($selectUsuario)){
            echo "<tr>";
              echo "<td>".$f[TEAM]."</td>";
              echo "<td>".$f[WINS]."</td>";
              echo "<td>".$f[KILLSCORE]."</td>";
              echo "<td>".($f[SCORE]-$f[KILLSCORE])."</td>";
              echo "<td>".$f[DEATH]."</td>";
              echo "<td>".$f[KILL_DEATH]."</td>";
              echo "<td>".$f[SCORE]."</td>";
              echo "<td>".$f[SCORE_PER_MINUTE]."</td>";
              echo "<td>".$f[PREVIOUS_PLACE]."</td>";
              echo "<td>".$f[MATCH_TYPE]."</td>";
              echo "<td>".$f[GAME]."</td>";
              echo "<td>".$f[DATE]."</td>";
            echo "</tr>";
            $resultado = count($f[DATE]);
            $sumaresultado=$resultado+$sumaresultado;
            $sumaKD=$f[KILL_DEATH]+$sumaKD;
            $sumaSPM=$f[SCORE_PER_MINUTE]+$sumaSPM;
          }
        ?>

    </table>
    <?php
    echo "<br>Average KILL/DEATH ".($sumaKD/$sumaresultado);
    echo "<br>Average SCORE PER MINUTE ".($sumaSPM/$sumaresultado);
    ?>
  </body>
</html>
