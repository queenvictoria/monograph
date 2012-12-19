; what is the difference between make and build ? in the cossey / buildkit example 
; `build` gets drupal core and patches it ( `distro` ) then retrieves the profile 
; and `make` gets contrib modules ( via buildkits drupal-org.make file ) and 
; additions from cossey
; removing later patches works but
; only addthis, colorbox and ctools are actually installed
; and only if --no-core is used .

; so build would run first
; followed by make

; Build Kit taking over
; ---------------------
; Include Build Kit install profile makefile via URL
; includes[] = http://drupalcode.org/project/buildkit.git/blob_plain/refs/heads/7.x-2.x:/drupal-org.make

; buildkit
core = 7.x
api = 2

; utils
projects[profiler][subdir] = "contrib"
; needs dev for devel generate support of dev version of field collection
projects[entity][subdir] = "contrib"
projects[entity][version] = "1.x-dev"
projects[views][subdir] = "contrib"
projects[panels][subdir] = "contrib"
projects[devel][subdir] = "developer"
projects[coder][subdir] = "developer"
projects[simplehtmldom][subdir] = "developer"
projects[devel_themer][subdir] = "developer"
projects[module_filter][subdir] = "developer"
projects[admin][subdir] = "contrib"
projects[admin_menu][subdir] = "contrib"
projects[varnish][subdir] = "contrib"
projects[admin_views][subdir] = "contrib"
projects[views_bulk_operations][subdir] = "contrib"



projects[libraries][subdir] = "contrib"
projects[transliteration][subdir] = "contrib"
projects[token][subdir] = "contrib"
projects[pathauto][subdir] = "contrib"
projects[globalredirect][subdir] = "contrib"
projects[xmlsitemap][subdir] = "contrib"
projects[google_analytics][subdir] = "contrib"
projects[page_title][subdir] = "contrib"
projects[metatags][subdir] = "contrib"
projects[wysiwyg][subdir] = "contrib"
projects[features][subdir] = "contrib"
projects[features][version] = "1.x-dev"
projects[less][subdir] = "contrib"
projects[sass][subdir] = "contrib"
projects[conditional_styles][subdir] = "contrib"
; patch features to handle shortcut sets http://drupal.org/node/986968
; projects[features][patch][986968] = http://drupal.org/files/issues/features.shortcut_sets_0.patch
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.4.2/ckeditor_3.4.2.tar.gz"
libraries[lessphp][download][type] = "git"
libraries[lessphp][download][url] = "git://github.com/leafo/lessphp.git"
libraries[lessphp][destination] = "libraries"   

; projects
projects[nodequeue][subdir] = "contrib"
projects[webform][subdir] = "contrib"

; content type widgets
projects[link][subdir] = "contrib"
projects[date][subdir] = "contrib"
projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.x-dev"

; social
projects[addthis][subdir] = "contrib"
projects[addthis][version] = "2.1-beta1"

; asset handling
; colorbox & libraries
projects[colorbox][subdir] = "contrib"

; libraries[colorbox][download][type] = "get"
; libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/tarball/master"
; libraries[colorbox][download][tag] = v2.1.2
libraries[colorbox][download][type] = "git"
libraries[colorbox][download][url] = "git://github.com/jackmoore/colorbox.git"
libraries[colorbox][destination] = "libraries"   

; media
projects[ctools][subdir] = "contrib"
projects[file_entity][subdir] = "contrib"
projects[file_entity][version] = "2.x-dev"
projects[media][subdir] = "contrib"
projects[media][version] = "2.x-dev"
; titles on media fields http://drupal.org/node/1034034
; possibly the error in drush make - confirmed - but its because these projects aren't downloaded
; projects[media][patch][1034034] = http://drupal.org/files/issues/media_field_title_reroll.patch
; projects[styles][subdir] = "contrib"
projects[media_youtube][subdir] = "contrib"
projects[media_vimeo][subdir] = "contrib"
projects[media_vimeo][version] = "1.x-dev"
; projects[media_vimeo][patch][1636032] = http://drupal.org/files/media_vimeo-proportional-sizes-1636032-1.patch
;; add in global configuration of vimeo player
; possibly the error in drush make - confirmed - but its because these projects aren't downloaded
; projects[media_vimeo][patch][1229304] = http://drupal.org/files/issues/video_display_settings.patch
projects[media_soundcloud][subdir] = "contrib"
projects[media_soundcloud][version] = "1.x-dev"
projects[insert][subdir] = "contrib"

; multifile upload
projects[plupload][subdir] = "contrib"
projects[plupload][version] = "1.x-dev"
; prevent conflict with field entity module
; projects[plupload][patch] = "http://drupal.org/files/issues/1240654-plupload-namespace-file-uri-to-object.patch"
libraries[plupload][download][type] = "git"
libraries[plupload][download][url] = "git://github.com/moxiecode/plupload.git"
libraries[plupload][destination] = "libraries"   


; themes
projects[tao][type] = "theme"
projects[tao][subdir] = "contrib"
projects[zen][type] = "theme"
projects[zen][subdir] = "contrib"
projects[omega][type] = "theme"
projects[omega][subdir] = "contrib"

