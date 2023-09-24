# #The following example will cause scenarios tagged with @fast to fail if the execution takes longer than 0.5 second

# #Around('@fast') do |scenario, block|
# #  Timeout.timeout(0.5) do
# #    block.call
# #  end
# #end

# #Before do
#   # Do something before each scenario.
# #end

# #Before do |scenario|
#   # The +scenario+ argument is optional, but if you use it, you can get the title,
#   # description, or name (title + description) of the scenario that is about to be
#   # executed.
#   Rails.logger.debug "Starting scenario: #{scenario.title}"
# #end

# #AfterStep do |scenario|
#   # Do something after each step.
# #end

# #Before('@cucumis, @sativus') do
#   # This will only run before scenarios tagged
#   # with @cucumis OR @sativus.
# #end

# #Before('@cucumis', '~@sativus') do
#   # This will only run before scenarios tagged
#   # with @cucumis AND NOT @sativus.
# #end

# #Before('@cucumis, @sativus', '@aqua') do
#   # This will only run before scenarios tagged
#   # with (@cucumis OR @sativus) AND @aqua
# #end

# #AfterStep('@cucumis', '@sativus') do
#   # This will only run after steps within scenarios tagged
#   # with @cucumis AND @sativus.
# #end


# # add this to ./features/support/hooks.rb
# After('@debug') do
#   puts response.body
# end

# # tag any features with @debug to get the output printed
# # especially handy for testing json and xml responses

# # File: features/support/hooks.rb
# #
# Before('@foo') do |scenario|
#   print "Before starting scenario #{scenario.name}"
# end

# After('@foo') do |scenario|
#   puts "> after scenario #{scenario.name}"
# end

# # File: features/support/hooks.rb
# #
# Around('@foo') do |scenario, block|
#   print "Before starting scenario #{scenario.name}"
#   block.call
#   puts "> after scenario #{scenario.name}"
# end

# AfterStep do |result, step_info|
#   print "Result: #{result} - Step: #{step_info.name}"
# end

# # After each scenario that fails, run the debugger, needs ruby-debug gem
# # How to use: cucumber DEBUG=1
# After do |s|
#   if s.failed?
#     debugger if ENV['DEBUG']
#     DatabaseCleaner.clean
#   end
# end
