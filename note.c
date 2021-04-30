8
5
6
4
1
2
3
7
9
10
11
12
13
14
15
mediane 8 et min 1

9	7
10	3
11	2
12	1
13	4
14	6
15	5
	8

bornemax 8 et bornemin 4

16 2 1 3 4 5 6 7 8 9 10 11 12 13 14 15



au dessus dquinze:

mediane :
	- si fsort est deja valide : alors le minimum commence apres le minimu
		sinon 0
	- reststack ca va donc etre le nombre de valeur a parser
	on cherche la valeur dans le reste de la stack qui aura autant de valeur au dessus que de valeur au dessus


	je viens de gerer is beetween et me reste donc q finir utilis 4 en partant de quick a

fmax  = max des valeur deja sort
newmin jlai change

On commence par bornemin bornemax : min et mediane : On s''arrete quand la mediane == minimum
	- aborneur : envoie dans b tout cquii est entre les deux bornes [min, medianq]=> appelle bborneur et lui envoie la mediane de b comme minimum
	- bborneur travail que si il a plus de 12 elements, sinon : clean et aborneur
		envoie tout caui est entre les borne dans a ([medianb, mediana])
			- appelle new_min
				veut que la premiere valeur admet au moins une valeur plus grande sans que ce soit le min
				si prem est min alors il qctive le flag sort ? : pck min sera dernier !

closest envoie min ou max selon ?
	-



Fonctionnement stp :

		fsort et fmax = 0
		bornemin commence au a.min
		{
			bornemax = mediana
				SI bornemin == bornemax (la mediane dans a == et le min de a ==)
			{
				ABORNEuer envoie tout cqui est emtre les deux bornes dans b
				BBorneur envoie le plus ptit ou le plus grand selon qui est le plus proche d''une extremite
				new_min influe sur A et surtout sur la a.prem :
						fsort = 1 si le min est tout devant
						il cherche une valeur au dessus de min dans la pile et qui serait plus petit que a.prem
									si il trouve pas alors il a sa place juste derriere le min et fmax (valer max deja range) = nvl valeur
									si il trouve alors tout est bon


			}

		}
