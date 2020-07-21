add_executable(main WIN32
  main.cpp

  state_machine.cpp
  state_machine.h
  state_machine_worker.cpp
  state_machine_worker.h

  my_widget.cpp
  my_widget.h

  my_other_widget.cpp
  my_other_widget.h

  progress_dialog.cpp
  progress_dialog.h
)
target_link_libraries(main Qt5::Core Qt5::Widgets)
