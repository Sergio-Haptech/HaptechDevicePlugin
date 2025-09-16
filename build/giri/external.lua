-- ///////////////////////////////////
-- ///////////////////////////////////
-- ///////////////////////////////////
-- WARNING
-- This file has been auto-generated.
-- Do NOT make modifications directly to it as they will be overwritten!
-- ///////////////////////////////////
-- ///////////////////////////////////
-- ///////////////////////////////////

-- Project names:
local base_name = 'M4DeviceReader'
local component_project_name = base_name
local library_project_name = base_name .. 'Library'
local unittest_project_name = base_name .. 'UnitTest'
local reloadingmodule_project_name = base_name .. 'ReloadingModule'

-- Projects:
if _ACTION == 'vs2010' then
externalproject( component_project_name )
  location ( project_root .. 'vs2010' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2010' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2010' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2010' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

if _ACTION == 'vs2012' then
externalproject( component_project_name )
  location ( project_root .. 'vs2012' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2012' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2012' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2012' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

if _ACTION == 'vs2013' then
externalproject( component_project_name )
  location ( project_root .. 'vs2013' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2013' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2013' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2013' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

if _ACTION == 'vs2015' then
externalproject( component_project_name )
  location ( project_root .. 'vs2015' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2015' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2015' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2015' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

if _ACTION == 'vs2017' then
externalproject( component_project_name )
  location ( project_root .. 'vs2017' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2017' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2017' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2017' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

if _ACTION == 'vs2019' then
externalproject( component_project_name )
  location ( project_root .. 'vs2019' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2019' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2019' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2019' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

if _ACTION == 'vs2022' then
externalproject( component_project_name )
  location ( project_root .. 'vs2022' )
  uuid ( '1b4eff29-f900-498b-9f03-2da43e54189c' )
  kind ( 'SharedLib' )
  language ( 'C++' )

externalproject( library_project_name )
  location ( project_root .. 'vs2022' )
  uuid ( '2e9221ea-cdac-4ad9-a0ed-6e1c4b3676c7' )
  kind ( 'StaticLib' )
  language ( 'C++' )

externalproject( unittest_project_name )
  location ( project_root .. 'vs2022' )
  uuid ( 'df6ecffa-d44b-4a43-bc40-300546f4a0a8' )
  kind ( 'ConsoleApp' )
  language ( 'C++' )

externalproject( reloadingmodule_project_name )
  location ( project_root .. 'vs2022' )
  uuid ( '9f1f9895-b801-4b19-9bf9-119d3ae52fb7' )
  kind ( 'SharedLib' )
  language ( 'C++' )
end

