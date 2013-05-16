require 'bundler'
require 'bundler/setup'

require 'serialport'
require 'celluloid'


class Machine
  include Celluloid::FSM

  def initialize
    @projects = {
      "ProjectA" => ["apples", "oranges", "bananas"],
      "ProjectB" => ["carrots", "edamame", "green peas"],
      "ProjectC" => ["agave syrup", "flour", "sugar"]
    }
    @pindex = 0
    @tindex = 0
  end

  default_state :waiting

  def project
    @projects.keys[@pindex]
  end

  def task
    @projects[project][@tindex]
  end

  state :waiting, to: :select_project do
    puts "waiting"
  end

  state :select_project, to: [:next_project, :select_task] do
    puts "Would you like to select #{project}?"
  end

  state :next_project do
    @pindex += 1
    @pindex = 0 if @pindex >= @projects.length
    transition :select_project
  end

  state :select_task, to: [:next_task, :pick_task] do
    puts "Would you like to select #{task}?"
  end

  state :next_task, to: [:select_task] do
    @tindex += 1
    @tindex = 0 if @tindex >= @projects[project].length
    transition :select_task
  end

  state :pick_task, to: [:waiting] do
    puts "Start timer for #{project} / #{task}"
    transition :waiting
  end

end

machine = Machine.new

# STATE               EVENT    DEST_STATE
# waiting             btn1     select_project
# select_project      btn1     next_project
# next_project        btn1     next_project
# select_project      btn2     pick_project
# next_project        btn2     pick_project
# pick_project        btn2     next_task
# next_task           btn2     next_task
# pick_project        btn3     pick_task
# next_task           btn3     pick_task

# select_project      TIMEOUT  waiting
# next_project        TIMEOUT  waiting
# pick_project        TIMEOUT  waiting
# next_task           TIMEOUT  waiting
