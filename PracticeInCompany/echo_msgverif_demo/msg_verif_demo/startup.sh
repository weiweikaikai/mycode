kill -TERM `ps -ef | grep "msgverif ./bench.conf" | grep -v grep | awk '{print $2}'`
sleep 1
./AsynServ  ./bench.conf
