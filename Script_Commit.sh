echo "Script Commit, para facilitarnos la vida :3\n"
echo "Creado por: Jp\n"
echo "Mensaje del Commit: "
read msgGit

git add .
git status
git commit -m `echo "$msgGit"`
git push origin master
