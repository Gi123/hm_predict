Чтобы собрать docker: sudo docker build --pull --rm -f "DockerFile" -t hmpredict:latest "."

Чтобы запустить: sudo docker run -it --rm hmpredict test.csv saved_model