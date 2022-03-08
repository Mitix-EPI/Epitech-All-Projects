cd docs
make clean
rm source/api.rst
rm source/app.rst
rm source/connection.rst
rm source/modules.rst
sphinx-apidoc -o source ../
make html