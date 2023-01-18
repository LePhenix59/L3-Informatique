<?php
include("loclahost/projet/inc/connexion.php"); 
include("loclahost/projet/class/Utilisateur.php");
$u = new Utilisateur();
$u->set_nom($_REQUEST['nom']);
$u->set_prenom($_REQUEST['prenom']);
$u->set_mail($_REQUEST['mail']);
$u->set_mdp($_REQUEST['mdp']);
$u->set_d_naissance($_REQUEST['dnaissance']);
if (...->...($bdd))
print "Ajout utilisateur ok.";
?>