#ifndef CONSOLE_HANDLER_H
#define CONSOLE_HANDLER_H

namespace epee {
template<class t_server>
bool default_console_handler(t_server* psrv) {
  TRY_ENTRY();
  bool continue_handle = true;
  while (continue_handle) {
    char command_buff[400] = { 0 };
    std::string command;
    std::cin.getline(command_buff, 399);
    if (std::cin.eof() || std::cin.fail()) {

      LOG_PRINT("std::cin.eof() or std::cin.fail(), stopping...", LOG_LEVEL_0);
      psrv->send_stop_signal();
      continue_handle = false;
      break;
    }
    command = command_buff;

    if (!command.compare("exit") || !command.compare("q")) {
      psrv->send_stop_signal();
      continue_handle = false;
    } else {
      std::cout << "unkonown command: " << command << std::endl;
    }
  }
  return true;
  CATCH_ENTRY_L0("console_handler", false);
}

template<class t_server>
bool start_default_console(t_server* ptsrv) {
  boost::thread(boost::bind(default_console_handler<t_server>, ptsrv));
  return true;
}

}

#endif  //  CONSOLE_HANDLER_H
