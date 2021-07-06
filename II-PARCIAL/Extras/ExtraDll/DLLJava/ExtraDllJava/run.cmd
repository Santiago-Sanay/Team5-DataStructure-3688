@echo off
call "C:\Program Files\NetBeans-12.1\netbeans\java\maven\bin\mvn.cmd" install
java -jar ./target/ExtraDllJava-1.0-SNAPSHOT-jar-with-dependencies.jar

pause
