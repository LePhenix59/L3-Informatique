<?php
include("loclahost/projet/class/Mysql.php");
$bdd = new mysql;
$serveur->set_serveur("localhost");
$login->set_login("root");
$mdp->set_mdp("root");
$bdd->set_bdd("Utilisateur");
$cnx->connexion();
?>