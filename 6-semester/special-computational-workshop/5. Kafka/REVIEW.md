# REVIEW

```sh
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS/kafka_2.13-3.4.0$ bin/zookeeper-server-start.sh config/zookeeper.properties
```

```sh
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS$ cd kafka_2.13-3.4.0/
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS/kafka_2.13-3.4.0$ bin/kafka-server-start.sh config/server.properties
```

```sh
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS$ cd kafka_2.13-3.4.0/
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS/kafka_2.13-3.4.0$ bin/kafka-topics.sh --create --topic quickstart-events --bootstrap-server localhost:9092
Created topic quickstart-events.
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS/kafka_2.13-3.4.0$ bin/kafka-console-producer.sh --topic quickstart-events --bootstrap-server localhost:9092
>za
>wardo
>hello
>
```

```sh
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS$ cd kafka_2.13-3.4.0/
astatochek@LAPTOP-UO46SGTQ:/mnt/c/Users/ASUS/kafka_2.13-3.4.0$ bin/kafka-console-consumer.sh --topic quickstart-events --from-beginning --bootstrap-server localhost:9092
za
wardo
hello



```
