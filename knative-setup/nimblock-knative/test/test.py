import threading
from input_data.standard_seq import *
import time
import subprocess


endpoint = "\"http://het-route.default.127.0.0.1.sslip.io\""
error_log_file = "log/log.txt"
log_file_base = "output_data/standard_seq_results_route.txt"
log_file = log_file_base

requests = []
#app_nums = input_data.input_seq.EventNumbers

def app_req(replay_num, command_num):
    command = requests[replay_num][command_num][0]
    #start timer
    #run curl request to endpoint
    print("Running: " + command)
    start_time = time.time()
    response = subprocess.run(command, shell=True, capture_output=True, text=True)
    end_time = time.time()
    temp_log_file = error_log_file + str(command_num)
    with open(temp_log_file, "w") as l: 
        l.write(response.stdout.strip())
        #f.write(response.stderr.strip())
        l.write("\n\n")
    response_times = response.stdout.strip()
    #end timer
    #log response time and returned nimblock response time
    requests[replay_num][command_num][1] = "Start time: " + str(start_time) + ", End time: " + str(end_time)
    requests[replay_num][command_num][2] = response_times
    return

def form_reqs():
    for i in range(len(EventNumbers)): 
        replay = []
        for j in range(len(EventNumbers[i])):
            command = "curl " + endpoint + " -H \"Content-Type:application/json\" -d "
            json = '\'{"app": ' + str(EventNumbers[i][j]) + ', "batch": ' + str(BatchNumbers[i][j]) + ', "priority": ' + str(PriorityNumbers[i][j]) + '}\''
            command = command + json
            replay.append([command, "", ""])
        requests.append(replay)
    #print(requests[0][0])

def run_replay(replay_num):
    threads = []
    replay = requests[replay_num]
    for i in range(len(replay)):
        threads.append(threading.Thread(target=app_req, args=(replay_num,i)))
        threads[i].start()
        time.sleep(DelayNumbers[replay_num][i])
    for i in range(len(replay)):
        threads[i].join()

def get_start_end(output):
    start_index = output.find("Start time: ")
    end_index = output.find(", End time: ")

    start_time_str = output[start_index + len("Start time: "):end_index]
    end_time_str = output[end_index + len(", End time: "):]

    string_out = "Start: " + str(start_time_str) + " End: " + str(end_time_str)
    return string_out

def get_request_json(req):
    start_index = req.find("-d '{")
    end_index = req.find("}'")

    req = req[start_index + len("-d '{"):end_index]
    return req

def parse_replay(replay_num):
    with open(log_file, "w") as f:
        f.write("               Request              |               Overall Response Time               |              Nimblock Response Time              \n")
        for request in requests[replay_run]:
            overall_response = get_start_end(request[1])
            nimblock_response = get_start_end(request[2])
            f.write(get_request_json(request[0]))
            f.write(" | ")
            f.write(overall_response)
            f.write(" | ")
            f.write(nimblock_response)
            f.write("\n")
form_reqs()
#print(requests)
for i in range(10):
    replay_run = i
    log_file = log_file_base + str(i)
    run_replay(replay_run)
    parse_replay(replay_run)
    time.sleep(60)
