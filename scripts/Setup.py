import os
import subprocess
import platform

from SetupPython import PythonConfiguration as PythonRequirements

PythonRequirements.Validate()


from SetupVulkan import VulkanConfiguration as VulkanRequirements


os.chdir('./../') 

VulkanRequirements.Validate()

if platform.system() == "Windows":
    print("\nRunning premake...")
    subprocess.call([os.path.abspath("./scripts/Win-GenProjects.bat"), "nopause"])

print("\nSetup completed!")
