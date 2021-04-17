# Projet IHM
## Siham JANATI

### Présentation du projet
Le but de ce projet est de concevoir une application pour une banque qui permettrait une visualisation des performances des différentes agences et des employés, et qui permettrait aussi à un banquier de voir ces performances personelles.
La réunion avec le directeur de la banque a donné lieu à la spécification que l'on présentera dans la prochaine partie. Les points les plus importants à respecter sont les suivants:
 - Avoir une page principale pour les performances des trois canaux séparément: bancaires, assurances et boursiers.
 - Avoir une page réservée pour la famille des prêts du canal bancaires
 - Permettre de voir les performances sur une durée déterminée
 - une IHM accessible à des personnes aux besoins spécifiques
 - la vision de nuit
 - Possibilité de voir les performances d'une agence en particulier, ou d'un employé, ou l'ensemble de leurs performances.

### Les différentes phases  

Nous avons suivi un processus incrémental. Tout d'abord, la spécification d'une IHM basique, le dessin des Wireframes, puis dessiner l'interface sur QT Designer.
Ensuite, la spécification de la couche logique, et son implémentation sur QT. Et finalement, l'ajout d'éléments bonus à l'IHM, et leur intégration à la couche logique et les modifications nécessaires à l'IHM de base pour y intégrer les nouveaux éléments bonus.

#### IHM de base
**Description**  
Le but est de concevoir une IHM qui répond d'abord aux critères définies précedemment, et de prendre en considération les points suivants:
- Elle doit être ergonomique et facile d'utilisation. L'utilisateur ne doit pas perdre son temps à naviguer l'application. Les élèments essentiels comme le choix de la vue ou de l'agence doivent être mis en avant, et les éléments les moins sollicités comme le darkmode seront moins visibles.
- Il faut que l'utilisateur soit toujours guidé et ne se perde pas, il doit toujours être informé sur l'état de l'application, et être guidé dans ces choix. Dans chaque vue il faudrait indiquer où l'utilisateur se trouve actuellement, il ne doit pas avoir à deviner dans quel vue il se trouve même si celà est "évident" en regardant les graphes affichés. L'utilisateur doit aussi avoir accès à un manuel d'utilisation. Celui-ci se trouve dans le menu "Aide".
- Il faudrait prendre en considération les utilisateurs aux besoins spécifiques:
* Les personnes dyslexiques: en mettant des icônes, des couleurs, et des images qui accompagnent le texte, ceci est utile même pour un utilisateur normal et aide à la mémorisation et l'apprentissage.  
* Les daltoniens: ne pas se suffir de la couleur et des icônes mais toujours accompagner de texte, créer des contrastes, et adopter les bonnes combinaisons de couleur.
* Les personnes handicapés: Possibilité d'agrandir les graphes pour les malvoyants.
- Le thème doit rester neutre avec des couleurs sobres et qui ne fatiguent pas la vue. L'utilisateur peut passer beaucoup de temps devant l'application, l'interface ne doit pas être chargée de couleurs et d'effets inutiles, pour cette raison je suis partie sur des monochromes.  
- Avec la mondialisation, l'application n'est pas addressée à des utilisateurs d'une culture spécifique mais les employés peuvent provenir de cultures différentes, une raison de plus pourquoi le thème et les couleurs doivent rester neutres. C'est pourquoi j'ai choisis un fond blanc légèrement bleuté, et des boutons de couleur plus foncés pour plus de visibilité.

**Contraintes**
Pour des contraintes techniques et des contraintes de temps, les fonctionalités suivantes n'ont pas pu être implémentées:
- Un système de detection de voix pour les personnes handicapées ou blessées, et pour les non-voyants
- Interface multi-support, notamment une application mobile et tablette pour les utilisateurs ne disposant pas d'un ordinateur, mais aussi pour faciliter l'accès à tout moment, mais aussi une application sur montre connectée pourrait être un plus: pour des notification et des rappels.
- Adaptation à un écran tactile
- Traduction pour les employés étrangers et les agences à l'étranger


**Wireframes**

**wireframes annotés**

**Passage sur QT**
L'étape suivante était de concevoir toutes les pages sur QT Designer. Ce fut biensur l'étape la plus facile à réaliser bien que elle pose quelques contraintes techniques comme l'absence de certains widgets qu'il faut importer notamment le date picker. Comme c'est la première fois que nous travaillons sur QT, je me suis focalisé d'abord sur la familarisation avec son interface.
J'ai rencontré des difficultés à modifier le style des widgets. Je me suis habitués aux logiciels de graphisme comme PhotoShop ou ces fonctionalités sont faciles d'accès, sur QT Designer, j'ai du faire plus d'efforts pour m'y retrouver.


#### Couche logique  
**Description**   


**Lier l'IHM à la couche logique**   

**Générer les données**   


#### Ajout d'éléments Bonus
**Description**   

**Design d'éléments graphiques sur PhotoShop**   

**Eléments Bonus dans l'IHM**   
