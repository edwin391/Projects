<?php
      $host     = "localhost";
      $user     = "root";
      $password = "jair.gandallin";
      $db = "NCGA";
      $conexion=mysql_connect($host,$user,$password) or die ("Problemas con servidor");
      mysql_select_db($db,$conexion) or die("Base de datos en mantenimiento");
?>

<html>
  <head>
  </head>
  
  <body>
  <a href="ranking.php">ranking</a>
    <form action="scriptAddingData.php" method="POST" enctype="multipart/form-data">
      <label>Kills</label>
      <input type="number" id="kill" name="kill"><br>
      
      <label>Deaths</label>
      <input type="number" id="death" name="death"><br>
        
      <label>Total score</label>
      <input type="number" id="score" name="score"><br>
      
      <label>Minutes of war</label>
      <input type="number" id="minutes" name="minutes"> <br>
      
      <label>Select Game</label>
      <select id="game" name="game">
        <option value="Halo">Halo</option>
        <option value="Call of Duty">Call of Duty</option>
      </select><br>
      
      <label>Match Type</label>
      <select id="match" name="match">
        <option value="Hardpoint">Hardpoint</option>
        <option value="Search and Destroy">Search and Destroy</option>
        <option value="Uplink">Uplink</option>
        <option value="Breakout">Breakout</option>
        <option value="Capture the flag">Capture the flag</option>
        <option value="Stronghold">Stronghold</option>
      </select><br>
      
      <label>Previous Place</label>
      <input type="number" id="place" name="place"><br>
      
      <label>New Gamers tag</label>
      <input type="text" id="tagnew" name="tagnew"> 
      OR
      <label>Existing Gamer tag</label>
      
      	<?php
      	$selectUsuario1=mysql_query("SELECT DISTINCT GAMER_TAG FROM RANKING ORDER BY SCORE_PER_MINUTE DESC", $conexion) or die(mysql_error());
      echo "<select id='tag' name='tag'>";
      while($y=mysql_fetch_array($selectUsuario1)){
        echo "<option>".$y[GAMER_TAG]."</option>";
        }
        ?>
      </select>

      <br>    
        
      <button type="submit" name="accion">Send Data</button>
    </form>
 <!---------------------------------------------------------------------------------------------------------->    
    <form action="scriptAddingTeam.php" method="POST" enctype="multipart/form-data">
      <label>New Team</label>
      <input type="text" id="newTeam" name="newTeam"><br> 
        
      <button type="submit" name="accion">Add Team</button>
    </form>
   
    <label>Teams</label>
    <select class="form-control">
    <?php
      $selectTeam=mysql_query("SELECT TEAMNAME FROM TEAMS", $conexion) or die(mysql_error());
      
      while($w=mysql_fetch_array($selectTeam)){
        echo "<option>".$w[TEAMNAME]."</option>";
      }
    ?>
        
    </select>
<!---------------------------------------------------------------------------------------------------------->
    <?php
      $selectUser=mysql_query("SELECT DISTINCT GAMER_TAG FROM RANKING WHERE TEAM='NOTEAM'", $conexion) or die(mysql_error());
      echo "<h1>LIST OF GAMERS WITHOUT TEAM</h1><br>";
      
      while($r=mysql_fetch_array($selectUser)){  
        echo "<form action=scriptAddingTeamToPlayer.php?name=".$r[GAMER_TAG]." method=POST enctype=multipart/form-data>";
        echo $r[GAMER_TAG];
    ?>
    <label>To</label>
    <select id="teamadding" name="teamadding">
    <?php
      $selectTeam=mysql_query("SELECT TEAMNAME FROM TEAMS", $conexion) or die(mysql_error());
      
      while($w=mysql_fetch_array($selectTeam)){
        echo "<option>".$w[TEAMNAME]."</option>";
      }
    ?>
    </select>
    
    <button type="submit" name="accion">Add Player</button>
    </form>
    <?php } ?>
      
      
<!---------------------------------------------------------------------------------------------------------->
    <?php
      $selectUsuario=mysql_query("SELECT DISTINCT GAMER_TAG FROM RANKING ORDER BY SCORE_PER_MINUTE DESC", $conexion) or die(mysql_error());
      echo "<h1>LIST OF GAMERS</h1><br>";
      
      while($f=mysql_fetch_array($selectUsuario)){
        echo "<a href='mostrar.php?usuario=".$f[GAMER_TAG]."'>".$f[GAMER_TAG]."</a><br>";
      }
    ?>

<!---------------------------------------------------------------------------------------------------------->
    <?php
      $selectUser=mysql_query("SELECT * FROM TEAMS", $conexion) or die(mysql_error());
      $selectPlayer=mysql_query("SELECT DISTINCT TEAM, GAMER_TAG FROM RANKING", $conexion) or die(mysql_error());
      while($row[] = mysql_fetch_assoc($selectPlayer));
      mysql_free_result($selectPlayer);
      mysql_close($conexion);
      array_pop($row);
      echo "<h1>TEAMS</h1><br>";
      
      while($r=mysql_fetch_array($selectUser)){ 
        echo $r[TEAMNAME]."<br>";
      	if($r[TEAMNAME]==NULL){
      	  break;
      	}
        foreach($row as $i){
          if($r[TEAMNAME]==$i[TEAM])
      	  echo $i[GAMER_TAG]."<br>";
      	}
      	echo "<br>";
      }
    ?>
      
      
<!---------------------------------------------------------------------------------------------------------->

  </body>
</html>
