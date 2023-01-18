<?php
class Mysql
{
private $_serveur = "localhost";
private $_login;
private $_mdp;
private $_bdd;
private $_cnx;
public function set_serveur($s)
{
$this->_serveur = $s;
}
public function set_login($s)
{
$this->_login = $s;
}
public function set_mdp($s)
{
$this->_mdp = $s;
}
public function set_bdd($s)
{
$this->_bdd = $s;
}
public function get_cnx()
{
return $this->_cnx;
}
public function connexion()
{
$this->_cnx = mysql_connect($this->_serveur, $this->_login, _mdp);
if (!$this->_cnx)
exit("Erreur de connexion bdd : " . mysql_error());
if (!mysql_select_db($this->_bdd))
exit("Erreur : bdd inexistante : " . mysql_error());
}
public function requete($q)
{
$res = mysql->query($q);
if (!$res) exit("<pre>Erreur dans la requete [$q] : " . mysql_error() . "</pre>");
return $res;
}
}
?>


