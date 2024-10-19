import os
import sys


# -- Project information -----------------------------------------------------
project = "Session_13_14_15"
author = "David Adeakin"
copyright = "2024, David"

# -- General configuration ---------------------------------------------------
extensions = ["breathe"]

# Breathe Configuration
breathe_default_project = project
breathe_default_members = ("members", "undoc-members")

breathe_projects = {
    "Session_13_14_15": os.path.join(os.path.dirname(__file__), "../../build/docs/doxygen/xml")
}

templates_path = ["_templates"]
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------
html_theme = "alabaster"
html_static_path = [os.path.abspath('_static')]





