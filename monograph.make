; what is the difference between make and build ? in the cossey / buildkit example 
; `build` gets drupal core and patches it ( `distro` ) then retrieves the profile 
; and `make` gets contrib modules ( via buildkits drupal-org.make file ) and 
; additions from cossey

; so build would run first
; followed by make

; Build Kit taking over
; ---------------------
; Include Build Kit install profile makefile via URL
includes[] = http://drupalcode.org/project/buildkit.git/blob_plain/refs/heads/7.x-2.x:/drupal-org.make

; utils
projects[entity][subdir] = "contrib"
projects[views][subdir] = "contrib"
projects[devel][subdir] = "developer"
projects[libraries][subdir] = "contrib"
projects[wysiwyg][subdir] = "contrib"
projects[features][subdir] = "contrib"
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.4.2/ckeditor_3.4.2.tar.gz"

; content type widgets
projects[link][subdir] = "contrib"
projects[date][subdir] = "contrib"
projects[field_collection][subdir] = "contrib"

; social
projects[addthis][subdir] = "contrib"
projects[addthis][version] = "2.1-beta1"

; asset handling
; colorbox & libraries
projects[colorbox][subdir] = "contrib"

libraries[colorbox][download][type] = "get"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/tarball/master"
; libraries[colorbox][download][tag] = v2.1.2
libraries[colorbox][destination] = "libraries"   

; media
projects[ctools][subdir] = "contrib"
projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "1.x-dev"
projects[media][subdir] = "contrib"
projects[media][version] = "2.x-dev"
projects[styles][subdir] = "contrib"
