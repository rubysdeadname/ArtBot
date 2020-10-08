#include "ArgumentHandler.hpp"
#include <string>

int ArgumentHandler::getIndexOf(std::string s)
{
  for (int i = 0; i < numberOfArguments; ++i)
  {
    if (arguments[i] == s)
      return i;
  }
  return -1;
}

std::string ArgumentHandler::getArgumentByKey(std::string key)
{
  int index = getIndexOf(key);
  return (index >= 0 && index < numberOfArguments) ? arguments[index + 1] : "";
}

std::string ArgumentHandler::getName()
{
  std::string arg = getArgumentByKey("-n");
  if (arg == "")
  {
    int seed = getSeed();
    if (seed > 0)
      arg = std::to_string(seed);
    else
      arg = "";
  }
  return arg;
}

unsigned int ArgumentHandler::getSeed()
{
  std::string arg = getArgumentByKey("-s");
  return arg == "" ? -1 : std::stoul(arg);
}

unsigned int ArgumentHandler::getWidth()
{
  std::string arg = getArgumentByKey("-w");
  return arg == "" ? 256 : std::stoul(arg);
}

ArgumentHandler::ArgumentHandler(int argc, char const *argv[])
{
  numberOfArguments = argc;
  for (int i = 0; i < numberOfArguments; ++i)
  {
    std::string str(argv[i]);
    arguments.push_back(str);
  }
}
