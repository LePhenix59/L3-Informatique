<?php
class Utilisateur
{
private $_id;
private $_nom;
private $_prenom;
private $_d_naissance;
private $_mail;
private $_mdp;

public function set_nom($s)
{
if (strlen($s) == 0) exit("Utilisateur : le nom est obligatoire");
$this->_nom = $s;
}
public function set_prenom($s)
{
if (strlen($s) == 0) exit("Utilisateur : le prenom est obligatoire");
$this->_prenom = $s;
}
public function set_mail($s)
{
if (strlen($s) == 0) exit("Utilisateur : le mail est obligatoire");
$this->_mail = $s;
}
public function set_mdp($s)
{
if (!$mdp) $s = "1234";
if (strlen($s)<5|| strlen($s)>15) exit("Utilisateur : le mdp doit être compris entre 4 et 15 caractères");
$this->_mdp=$s;
}
public function set_dnaissance($s) // format d'entrés : jj/mm/aaaa
{
$this->_d_naissance = $s;
}
public function set_id($x)
{
$this->_id = $x;
}
public function enregistrer(Mysql $bdd)
{
$q = "INSERT INTO utilisateur (id, nom, prenom, dnaissance, mail, mdp)
VALUES (null, '$this->_nom', '$this->_prenom', '$this->_d_naissance', '$this->_mail', '$this->_mdp')";
return $bdd->$q;
}
function supprimer()
{
sql	="DELETE FROM `utilisateur` WHERE `id`=:id";
$query=$bdd->prepare($sql);
$query->bindParam(':id',$id,PDO::PARAM_INT);
$id=1;
$query->execute();
if($query->rowCount()>0)	{	
$count=$query->rowCount();
echo$count."rows were affected.";	
}	
else	
{
echo"No	affected rows.";	
}	
	
}
}
?>